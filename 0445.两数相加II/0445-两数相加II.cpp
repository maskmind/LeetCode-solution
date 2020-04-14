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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *revL1=reverseList(l1);
        ListNode *revL2=reverseList(l2);
        ListNode *p=revL1,*q=revL2,*head=NULL,*tail=NULL;
        int carry=0;
        while(p!=NULL||q!=NULL){
            int sum=carry;
            if (p!=NULL)
            {
                sum+=p->val;
            }
            if (q!=NULL)
            {
                sum+=q->val;
            }
            if (sum>9)
            {
                carry=1;
                sum=sum%10;
            }else{
                carry=0;
            }
            ListNode *tmp=new ListNode(sum);
            if (head==NULL)
            {
                head=tmp;
                tail=tmp;
            }else{
                tail->next=tmp;
                tail=tail->next;
            }
            if (p)
            {
                p=p->next;
            }
            if (q)
            {
                q=q->next;
            }
        }
        if (carry==1)
        {
            ListNode* node=new ListNode(1);
            tail->next=node;
        }
        return reverseList(head);


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