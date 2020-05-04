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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // create head node
        ListNode *node=new ListNode(-1);
        node->next=head;
        head=node;

        ListNode *p=head;
        while(p!=NULL){
            ListNode *q=p->next;
            int cnt=0;
            bool change =false;
            while(q!=NULL){
                cnt +=q->val;
                if(cnt==0){
                    p->next=q->next;
                    change=true;

                    break;
                }
                q=q->next;
            }
            if (!change)
            {
                p=p->next;
            }
        }
        
        return head->next;

    }
};