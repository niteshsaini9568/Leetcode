class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 0);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        for (auto &eq : equations) {
            if (eq[1] == '=') {
                Union(eq[0] - 'a', eq[3] - 'a', parent, rank);
            }
        }

        for (auto &eq : equations) {
            if (eq[1] == '!') {
                int a = find(eq[0] - 'a', parent);
                int b = find(eq[3] - 'a', parent);
                if (a == b) return false;  
            }
        }

        return true;
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
            if (rank[a_parent] > rank[b_parent]) {
                parent[b_parent] = a_parent;
            } else if (rank[b_parent] > rank[a_parent]) {
                parent[a_parent] = b_parent;
            } else {
                parent[b_parent] = a_parent;
                rank[a_parent]++;
            }
        }
    }
};
