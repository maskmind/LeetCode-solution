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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return ;
        ListNode *p=head->next,*q=head;
        while(p!=NULL&&p->next!=NULL){
            p=p->next->next;
            q=q->next;
        }

        ListNode *afterReverse=reverseList(q);

      

        ListNode *rt=head;
        p=head,q=afterReverse;
        while(q!=NULL&&p!=NULL){
            p = p->next;
            rt->next = q;
            q = q->next;
            rt->next->next = p;
            rt = p;
        }
        if (p!=NULL)
        {
            rt->next=NULL;
        }

    }

    ListNode* reverseList(ListNode* head) {
        if (head==NULL)
        {
            return head;
        }
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        ListNode* p=head,*tmp,*q;
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