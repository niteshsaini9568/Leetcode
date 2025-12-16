class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if (edges < n - 1) return -1;

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;

        for (auto &c : connections) {
            int a_parent = find(c[0], parent);
            int b_parent = find(c[1], parent);

            if (a_parent != b_parent) {
                Union(a_parent, b_parent, parent, rank);
                components--;
            }
        }

        return components - 1;
    }

private:
    int find(int i, vector<int>& parent) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i], parent);
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int a_parent = find(a, parent);
        int b_parent = find(b, parent);

        if (a_parent != b_parent) {
            if (rank[a_parent] > rank[b_parent])
                parent[b_parent] = a_parent;
            else if (rank[b_parent] > rank[a_parent])
                parent[a_parent] = b_parent;
            else {
                parent[b_parent] = a_parent;
                rank[a_parent]++;
            }
        }
    }
};
