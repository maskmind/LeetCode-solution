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
    int sum=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        convertBST(root->right);
        root->val +=sum;
        sum=root->val;
        convertBST(root->left);
        return root;
    }
};