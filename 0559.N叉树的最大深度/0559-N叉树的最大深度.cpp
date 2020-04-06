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
    int maxDepth(Node* root) {
        if(root==NULL)return 0;
        dfs(root,1);
        return maxLevel;
        
    }
    void dfs(Node *root,int level){
        if (root->children.size()==0)
        {
            if (level>maxLevel)
            {
                maxLevel=level;
            }
           
        }
        vector<Node*> v=root->children;
        for (int i = 0; i < v.size(); ++i)
        {
            dfs(v[i],level+1);
        }
    }
};