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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int st=0;
        vector<int> vec;
        if (dfs(root,st,voyage,vec))
        {
            return vec;
        }
        return vector<int>{-1};

    }
    bool dfs(TreeNode*root,int &index,vector<int>&voyage,vector<int>& vec){
        if (!root ||index >= voyage.size()) return true;
        if (root->val!=voyage[index])
        {
            return false;
        }
        index++;
        if (root->left&&root->left->val!=voyage[index])
        {
            vec.push_back(root->val);
            TreeNode*tmp=root->left;
            root->left=root->right;
            root->right=tmp;
        }
        return dfs(root->left,index,voyage,vec)&&dfs(root->right,index,voyage,vec);
        
    }
};