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
    int deepestLeavesSum(TreeNode* root) {
        if (root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> q;
        TreeNode* p=root;
        q.push(p);
        int res=0;
        while(!q.empty()){
            int len=q.size();
            res=0;
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

        }
        return res;



    }
};