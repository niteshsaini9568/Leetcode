class Solution {
public:
    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        visited[u] = true;

        for(auto v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(N, false);
        int count = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i = 0; i < N; i++){
            if(!visited[i]){
                count++;
                DFS(adj, i, visited);
            }
        }

        return count;

    }
};
