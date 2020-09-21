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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return sum;

        if (root->left&&!root->left->left&&!root->left->right)
        {
            sum+=root->left->val;
        }

        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);


        return sum;

    }
};