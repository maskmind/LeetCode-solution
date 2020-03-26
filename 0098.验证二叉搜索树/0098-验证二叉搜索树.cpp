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
    vector<int> v;
    bool isValidBST(TreeNode* root) {
        inOrderTree(root);
        if (v.size()==0)
        {
            return true;
        }
        for (int i = 0; i < v.size()-1; ++i)
        {
            if(v[i]>=v[i+1])return false;
        }
        return true;
    }
    void inOrderTree(TreeNode* root){
        if(root==NULL)return;
        inOrderTree(root->left);
        v.push_back(root->val);
        inOrderTree(root->right);
    }

};