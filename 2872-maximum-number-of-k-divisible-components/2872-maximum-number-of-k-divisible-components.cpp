class Solution {
public:
    int DFS(vector<vector<int>>& adj, int u, vector<int>& values, vector<bool>& visited, int k, int& count) {
        visited[u] = true;

        long long sum = values[u];  

        for (int v : adj[u]) {
            if (!visited[v]) {
                long long childSum = DFS(adj, v, values, visited, k, count);
                sum += childSum;
                sum %= k;
            }
        }

        if (sum % k == 0) {
            count++;
            return 0;      
        }

        return sum % k;    
    }


    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int count = 0;

        DFS(adj, 0, values, visited, k, count);

        return count;
    }
};
