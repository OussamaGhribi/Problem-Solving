class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }

    void dfs(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;

        path.push_back(node->val);
        target -= node->val;

        if (!node->left && !node->right && target == 0) {
            res.push_back(path);
        } else {
            dfs(node->left, target, path, res);
            dfs(node->right, target, path, res);
        }

        path.pop_back();
    }
};
