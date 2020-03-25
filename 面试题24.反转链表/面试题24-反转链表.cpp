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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL)
        {
            return head;
        }
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        ListNode* p=head,*tmp,*q=tail;
        while(p!=tail){
            //¶Ï¿ª
            tmp=p;
            p=p->next;
            //Á¬½Ó
            q=tail->next;
            tail->next=tmp;
            tmp->next=q;

        }
        return tail;


    }
};