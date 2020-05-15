/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s,t);
    }
    bool dfs(TreeNode*s,TreeNode*t){

        if (!s)return false;
        return checkRule(s,t)||dfs(s->left,t)||dfs(s->right,t);
        
    }
    bool checkRule(TreeNode* o,TreeNode* t){
        if (!o&&!t)return true;
        if ((o&&!t)||(!o&&t)||(o->val!=t->val))
        {
            return false;
        }
        return checkRule(o->left,t->left)&&checkRule(o->right,t->right);
    }
};