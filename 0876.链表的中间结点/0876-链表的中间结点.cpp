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
    ListNode* middleNode(ListNode* head) {
        ListNode *p=head,*q=head;        
        while(q!=NULL&&q->next!=NULL){
          q=q->next->next;
          p=p->next;
        }
        return p;
    }
};