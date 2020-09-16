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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if (!root)
        {
            return res;
        }

        while(!stk.empty()||root!=nullptr){
            while(root){
                stk.push(root);
                root=root->left;
            }
            TreeNode* p=stk.top();stk.pop();

            int VVal=p->val;
            res.push_back(VVal);
            root=p->right;
        }

        return res;
    }
    
};