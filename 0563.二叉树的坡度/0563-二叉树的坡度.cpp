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
    int postorder(TreeNode* root,int &val){
        if (root==NULL)
        {
            return 0;
        }
        int left=postorder(root->left,val);
        int right=postorder(root->right,val);
        val+=abs(left-right);
        return left+right+root->val;

    }
    int findTilt(TreeNode* root) {
        int val=0;
        postorder(root,val);
        return val;



    }
};