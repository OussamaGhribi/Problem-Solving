/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        int inv = -1;
        if(!root) return res;

        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int s = q.size();
            inv = -inv;
            for(int i = 0 ; i < s ; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);        
            }
            if(inv == -1){
                reverse(level.begin() , level.end());
            }
            res.push_back(level);
        }
        return res;
    }
};
