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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)return 0;
        int maxlevel=1;
        queue<pair<TreeNode*,unsigned long long>> que;
        que.push({root,1});
        while(!que.empty()){
            int len=que.size();
            maxlevel=max(maxlevel,int(que.back().second-que.front().second+1));
            while(len--){
                TreeNode *tmp=que.front().first;
                unsigned long long pos=que.front().second;que.pop();
                if (tmp->left)que.push({tmp->left,2*pos});
                if (tmp->right)que.push({tmp->right,2*pos+1});
                
                
            }
        }
        return maxlevel;
    }
};