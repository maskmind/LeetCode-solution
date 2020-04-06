/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> res;
        if (tree==NULL)
        {
            return res;
        }
        

        queue<TreeNode*> q;
        TreeNode* p=tree;
        q.push(p);
        while(!q.empty()){
            int len=q.size();
            ListNode *head= new ListNode(-1);
            ListNode *tail=head;
            while(len--){
                p=q.front();
                q.pop();
                ListNode* input=new ListNode(p->val);
                tail->next=input;
                tail=tail->next;
                if (p->left!=NULL)
                {
                    q.push(p->left);
                }
                if (p->right!=NULL)
                {
                    q.push(p->right);
                }

            }
            res.push_back(head->next);

        }
        return res;



    }
};