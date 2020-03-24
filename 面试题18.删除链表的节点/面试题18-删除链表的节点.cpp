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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val){
            head=head->next;
            return head;
        }
        ListNode *p=head;
        while(p->next!=NULL&&p->next->val!=val){
            p=p->next;
        }
        p->next=p->next->next;
        return head;
    }
};