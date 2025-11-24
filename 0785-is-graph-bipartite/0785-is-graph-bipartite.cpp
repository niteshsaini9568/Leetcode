class Solution {
public:
    bool DFS(vector<vector<int>>& graph, int curr, vector<int>& color, int currColor){
        color[curr] = currColor;

        for (auto v : graph[curr]) {
            if (color[v] == currColor) return false;

            if (color[v] == -1) {
                if (!DFS(graph, v, color, 1 - currColor))
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!DFS(graph, i, color, 0))
                    return false;
            }
        }

        return true;
    }
};
