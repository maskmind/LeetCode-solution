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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        if (root==NULL)
        {
            return 0;
        }
        vector<int> eachLevelSum;
        TreeNode* p=root;
        q.push(p);
        while(!q.empty()){
            int len=q.size();
            int res=0;
            while(len--){
                p=q.front();
                q.pop();
                res+=p->val;
                if (p->left!=NULL)
                {
                    q.push(p->left);
                }
                if (p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
            eachLevelSum.push_back(res);
        }
        int index=0,max=eachLevelSum[0];
        for (int i = 0; i < eachLevelSum.size(); ++i)
        {
            if (max<eachLevelSum[i])
            {
                max=eachLevelSum[i];
                index=i;
            }
        }
        return index+1;
    }
};