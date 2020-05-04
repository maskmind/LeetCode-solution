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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rt;
        if (!root)
        {
            return rt;
        }
        queue<TreeNode*> q;
        TreeNode *tmp=NULL;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            vector<int> inse;
            while(len--){
                tmp=q.front();q.pop();
                inse.push_back(tmp->val);
                if (tmp->left)
                {
                    q.push(tmp->left);
                }
                if (tmp->right)
                {
                    q.push(tmp->right);
                }

            }
            rt.push_back(inse);
        }
        for (int i = 0; i < rt.size(); ++i)
        {
            if (i%2==1)
            {
                reverse(rt[i].begin(),rt[i].end());
            }
        }
        return rt;
    }
};