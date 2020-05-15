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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        map<TreeNode*, TreeNode*> mp;
        vector<int> res;
        set<TreeNode*>visited;
        if (K==0)
        {
            return vector<int>{target->val};
        }
        changeToGraph(root,mp);
        int step=0;
        queue<TreeNode*> Queue;
        Queue.push(target);
        visited.insert(target);
        while(!Queue.empty()){
            int len=Queue.size();
            step++;
            while(len--){
                TreeNode* p=Queue.front();Queue.pop();
                if (p->left&&!visited.count(p->left))
                {
                    if (step==K)
                    {
                        res.push_back(p->left->val);
                    }
                    Queue.push(p->left);
                    visited.insert(p->left);
                }
                if (p->right&&!visited.count(p->right))
                {
                    if (step==K)
                    {
                        res.push_back(p->right->val);
                    }
                    Queue.push(p->right);
                    visited.insert(p->right);
                }
                if (mp[p] && !visited.count(mp[p])) {
                    if (step == K) {
                        res.push_back(mp[p]->val);
                    }     
                    Queue.push(mp[p]);
                    visited.insert(mp[p]);
                }
            }
            if (step == K)
                break;
        }

        return res;
    }
    void changeToGraph(TreeNode* root,map<TreeNode*,TreeNode* > &mp){
        if (root==NULL)
        {
            return ;
        }
        if (root->left!=NULL)
        {
            mp[root->left]=root;
        }
        if (root->right!=NULL)
        {
            mp[root->right]=root;
        }
        changeToGraph(root->left,mp);
        changeToGraph(root->right,mp);
    }
};