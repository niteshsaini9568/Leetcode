class Solution {
    struct Node {
        int minVal;
        int maxVal;
    };
    
    vector<Node> tree;
    vector<int> lazy;
    int n;

    void push(int v, int tl, int tr) {
        if (lazy[v] != 0) {
            tree[2 * v].minVal += lazy[v];
            tree[2 * v].maxVal += lazy[v];
            lazy[2 * v] += lazy[v];
            
            tree[2 * v + 1].minVal += lazy[v];
            tree[2 * v + 1].maxVal += lazy[v];
            lazy[2 * v + 1] += lazy[v];
            
            lazy[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[v].minVal += add;
            tree[v].maxVal += add;
            lazy[v] += add;
        } else {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(r, tm), add);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
            tree[v].minVal = min(tree[2 * v].minVal, tree[2 * v + 1].minVal);
            tree[v].maxVal = max(tree[2 * v].maxVal, tree[2 * v + 1].maxVal);
        }
    }

    int findFirstZero(int v, int tl, int tr, int limit) {
        if (tree[v].minVal > 0 || tree[v].maxVal < 0) return -1;
        if (tl > limit) return -1;
        
        if (tl == tr) {
            return (tree[v].minVal == 0) ? tl : -1;
        }
        
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        
        int res = -1;
        if (tree[2 * v].minVal <= 0 && tree[2 * v].maxVal >= 0) {
            res = findFirstZero(2 * v, tl, tm, limit);
        }
        
        if (res != -1) return res;
        
        if (tm + 1 <= limit && tree[2 * v + 1].minVal <= 0 && tree[2 * v + 1].maxVal >= 0) {
            res = findFirstZero(2 * v + 1, tm + 1, tr, limit);
        }
        
        return res;
    }

public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return 0;
        
        tree.assign(4 * n, {0, 0});
        lazy.assign(4 * n, 0);
        
        unordered_map<int, int> last_pos;
        int max_len = 0;
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int prev = last_pos.count(val) ? last_pos[val] : -1;
            
            int change = (val % 2 != 0) ? -1 : 1;
            
            update(1, 0, n - 1, prev + 1, i, change);
            
            last_pos[val] = i;
            
            int l = findFirstZero(1, 0, n - 1, i);
            if (l != -1) {
                max_len = max(max_len, i - l + 1);
            }
        }
        
        return max_len;
    }
};