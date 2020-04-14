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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str="";
        dfs(res,root,str);
        return res;

    }
    void dfs(vector<string>&res,TreeNode*root,string str){
        if (root==NULL)
        {
            return;
        }
       
        if (root->left==NULL&&root->right==NULL)
        {
            str+=to_string(root->val);
            res.push_back(str);
            return ;
        }
        dfs(res,root->left,str+to_string(root->val)+"->");
        dfs(res,root->right,str+to_string(root->val)+"->");
    }
};