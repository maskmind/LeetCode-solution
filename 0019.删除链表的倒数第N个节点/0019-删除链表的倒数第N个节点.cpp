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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL)
        {
            return head;
        }
        ListNode *st=new ListNode(-1);
        ListNode *p= st,*q=st;
        st->next=head;
        while(n--)
        {
            // less than n
            p=p->next;
        }
        while(p->next!=NULL){
            p=p->next;
            q=q->next;
        }
        q->next=q->next->next;
      
        return st->next;
    }
};