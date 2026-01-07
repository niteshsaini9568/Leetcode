class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;
    ll max_product = 0;

    ll total_sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + total_sum(root->left) + total_sum(root->right);
    }

    ll dfs(TreeNode* root, ll total) {
        if (!root) return 0;

        ll left = dfs(root->left, total);
        ll right = dfs(root->right, total);

        ll subtree = left + right + root->val;
        ll remaining = total - subtree;

        max_product = max(max_product, subtree * remaining);

        return subtree;
    }

    int maxProduct(TreeNode* root) {
        ll sum = total_sum(root);
        dfs(root, sum);
        return max_product % MOD;
    }
};
