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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> recordPath;
        if (root==NULL)
        {
            return recordPath;
        }
        TreeNode*p=root;
        vector<int> pa;
        preOrderR(p,sum,recordPath,pa);       
        return recordPath;       
    }
    void preOrderR(TreeNode* root,int target,vector<vector<int>>&recordPath,vector<int> v){
        if (root==NULL)
        {
            return;
        }
        v.push_back(root->val);
        if (root->left==NULL&&root->right==NULL&&root->val==target)
        {
            recordPath.push_back(v);
            return;
        }
        preOrderR(root->left,target-root->val,recordPath,v);
        preOrderR(root->right,target-root->val,recordPath,v);


    }

};