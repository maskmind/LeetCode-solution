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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructCore(nums,0,nums.size());

    }
    TreeNode* constructCore(vector<int>& nums,int head,int tail ){
        if (head==tail)
        {
            return NULL;
        }
        int max_index=findMax(nums,head,tail);
        TreeNode* root=new TreeNode(nums[max_index]);
        root->left=constructCore(nums,head,max_index);
        root->right=constructCore(nums,max_index+1,tail);
        return root;
    }
    int findMax(vector<int>&nums,int l,int r){
        int index=l,max=nums[l];

        for (int i = l; i < r; ++i)
        {
            if (max<nums[i])
            {
                max=nums[i];
                index=i;
            }
        }
        return index;
    }
};