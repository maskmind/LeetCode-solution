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
    bool isBalanced(TreeNode* root) {
        if (root==NULL)
        {
            return true;
        }

        if (abs(maxDepth(root->left)-maxDepth(root->right))<2)
        {
            return isBalanced(root->left)&&isBalanced(root->right);
        }
        return false;
    }
    int maxDepth(TreeNode* root){
        if (root==NULL)
        {
            return 0;
        }
        if (root->left==NULL&&root->right==NULL)
        {
            return 1;
        }
        int de=max(maxDepth(root->left),maxDepth(root->right))+1;
        return de;
    }
};