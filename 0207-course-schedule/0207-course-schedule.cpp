class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Typical Topological Sort

        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> adj;
        vector<int> result;
        queue<int> qu;

        for(auto vec : prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++){
            for(auto v : adj[i]){
                indegree[v]++;
            }
        }

        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }

        while(!qu.empty()){
            int u = qu.front();
            result.push_back(u);
            qu.pop();

            for(auto v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    qu.push(v);
                }
            }
        }

        return result.size() == n;
    }
};