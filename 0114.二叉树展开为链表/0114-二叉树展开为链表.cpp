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
    void flatten(TreeNode* root) {
        TreeNode* p=root;
        while(p!=NULL){
            if (p->left!=NULL)
            {
                TreeNode* pre=p->left;
                while(pre->right!=NULL)pre=pre->right;
                pre->right=p->right;         
                p->right=p->left;
                p->left=NULL;
            }else{
                p=p->right;
            }
            
        }
    }
};