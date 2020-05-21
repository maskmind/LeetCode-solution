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
    ListNode* sortList(ListNode* head) {
        if (head==NULL||head->next==NULL)
        {
            return head;
        }
        
        ListNode *newHead=new ListNode(INT_MIN);
        newHead->next=head;
        ListNode *pre=newHead,*p=head,*tail;
        while(p!=NULL){
            tail=p->next;

            
            if (tail!=NULL&&tail->val<p->val)
            {
                while(pre->next!=NULL&&pre->next->val<tail->val){
                    pre=pre->next;
                }

                ListNode* tmp=tail->next;
                tail->next=pre->next;
                pre->next=tail;
                //É¾³ýtail
                p->next=tmp;
                pre=newHead;
                
            }else{
                //ÓÐÐò
                p=tail;
            }
        }
        return newHead->next;




    }
};