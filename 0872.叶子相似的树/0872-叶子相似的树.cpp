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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        dfs(v1,root1);dfs(v2,root2);
        if (v1.size()!=v2.size())
        {
            return false;
        }else{
            for (int i = 0; i < v1.size(); ++i)
            {
                if (v1[i]!=v2[i])
                {
                    return false;
                }
            }
        }
        return true;
        
    }
    void dfs(vector<int>&res,TreeNode* root){
        if (root==NULL)
        {
            return ;
        }
        if (root->left==NULL&&root->right==NULL)
        {
            res.push_back(root->val);
            return;
        }
        dfs(res,root->left);
        dfs(res,root->right);
    }
};