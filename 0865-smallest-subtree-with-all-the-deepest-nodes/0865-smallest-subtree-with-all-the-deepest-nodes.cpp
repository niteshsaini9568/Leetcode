class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        using NodeDepthPair = pair<TreeNode*, int>;
        auto findDeepestSubtree = [&](this auto&& findDeepestSubtree, TreeNode* node) -> NodeDepthPair {
            if (!node) {
                return {nullptr, 0};
            }
          
            auto [leftSubtree, leftDepth] = findDeepestSubtree(node->left);
            auto [rightSubtree, rightDepth] = findDeepestSubtree(node->right);
          
            if (leftDepth > rightDepth) {
                return {leftSubtree, leftDepth + 1};
            }
          
            if (leftDepth < rightDepth) {
                return {rightSubtree, rightDepth + 1};
            }

            return {node, leftDepth + 1};
        };
    
        return findDeepestSubtree(root).first;
    }
};