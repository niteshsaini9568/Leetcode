from flask import Flask, jsonify
import requests
import random
import base64
import os
from datetime import datetime
from dotenv import load_dotenv

load_dotenv()
GITHUB_TOKEN = os.getenv("TOKEN")
USERNAME = "niteshsaini9568" 

if not GITHUB_TOKEN:
    raise Exception("TOKEN is not set in environment variables!")

app = Flask(__name__)

commit_messages = [
    "Refactored code for better readability", 
    "Fixed a bug causing unexpected crashes", 
    "Added support for new feature",
]

def get_repos():
    url = f"https://api.github.com/users/{USERNAME}/repos"
    headers = {"Authorization": f"token {GITHUB_TOKEN}"}
    response = requests.get(url, headers=headers)
    return response.json() if response.status_code == 200 else None

def commit_to_repo(repo_name, file_path, commit_message, content):
    url = f"https://api.github.com/repos/{USERNAME}/{repo_name}/contents/{file_path}"
    headers = {"Authorization": f"token {GITHUB_TOKEN}"}
    content_encoded = base64.b64encode(content.encode()).decode()

    payload = {"message": commit_message, "content": content_encoded, "branch": "main"}
    response = requests.put(url, headers=headers, json=payload)
    return response.status_code in [200, 201]

@app.route('/commit', methods=['POST'])
def commit_cycle():
    repos = get_repos()
    if not repos:
        return jsonify({"error": "No repositories found"}), 404

    owned_repos = [repo for repo in repos if not repo.get('fork', False)]
    if not owned_repos:
        return jsonify({"error": "No owned repositories found"}), 404

    random_repo = random.choice(owned_repos)
    repo_name = random_repo['name']
    folder_path = "config"
    commit_count = random.randint(1, 15)
    commits = []

    for _ in range(commit_count):
        commit_message = random.choice(commit_messages)
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        content = f"Commit at {timestamp} with message: {commit_message}"
        file_path = f"{folder_path}/commit_{timestamp.replace(':', '-').replace(' ', '_')}.txt"

        if commit_to_repo(repo_name, file_path, commit_message, content):
            commits.append({"repo": repo_name, "message": commit_message, "status": "success"})
        else:
            commits.append({"repo": repo_name, "message": commit_message, "status": "failed"})

    return jsonify({"commits": commits}), 200
