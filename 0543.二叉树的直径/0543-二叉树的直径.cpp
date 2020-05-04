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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        maxDept(root,ans);
        return ans ;

    }
    int maxDept(TreeNode* root,int &ans){
        if (!root)
        {
            return 0;
        }
        int left=maxDept(root->left,ans);
        int right=maxDept(root->right,ans);
        ans=max(ans,left+right);
        return max(left,right)+1;
    }
};