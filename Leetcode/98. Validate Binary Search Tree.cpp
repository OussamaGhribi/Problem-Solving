class Solution {
public:
    long prev = LONG_MIN;
    
    bool dfs(TreeNode* root) {
        if (!root) return true;

        if (!dfs(root->left)) return false;

        if (root->val <= prev) return false;
        prev = root->val;

        return dfs(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};
