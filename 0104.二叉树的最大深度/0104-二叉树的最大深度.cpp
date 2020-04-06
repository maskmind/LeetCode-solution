/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    int maxLevel=0;
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL)
        {
            return 0;
        }
        if (root->left==NULL&&root->right==NULL)
        {
            return 1;
        }
        int leftpart=maxDepth(root->left);
        int rightpart=maxDepth(root->right);
        int tmp=max(leftpart,rightpart)+1;
        return tmp;
        
    }
    
};