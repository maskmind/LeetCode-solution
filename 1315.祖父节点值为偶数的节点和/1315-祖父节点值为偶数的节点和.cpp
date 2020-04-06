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
private:
    int res=0;
public:
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return res;

    }
    void dfs(TreeNode* root){
        if (root==NULL)
        {
            return ;
        }
        if (root->val%2==0)
        {
            if (root->left)
            {
                if (root->left->left)res+=root->left->left->val;
                if (root->left->right)res+=root->left->right->val;                
            }
            if (root->right)
            {
                if (root->right->left)res+=root->right->left->val;
                if (root->right->right)res+=root->right->right->val;                
            }
        }
        dfs(root->left);
        dfs(root->right);

    }
};