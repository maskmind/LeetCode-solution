/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(res,0,root);
        return res;

    }
    void dfs(vector<int>& res,int level,TreeNode* root){
        if (root==NULL)
        {
            return;
        }
        if (level==res.size())
        {
            res.push_back(root->val);
        }
        dfs(res,level+1,root->right);
        dfs(res,level+1,root->left);
    }
};