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
    int sumNumbers(TreeNode* root) {
        if (root==NULL)return 0;
        int sum=0,tmp=0;
        TreeNode*p=root;
        vector<TreeNode*> path;
        vector<int > v;
        while(p||!path.empty()){
            while(p){
                tmp=tmp*10+p->val;
                v.push_back(tmp);
                path.push_back(p);
                p=p->left;
            }
            p=*path.rbegin();path.pop_back();
            tmp=*v.rbegin();v.pop_back();
            if(p->right==NULL&&p->left==NULL) sum=sum+tmp;
            p=p->right;
        }
        return sum;
    }

};
