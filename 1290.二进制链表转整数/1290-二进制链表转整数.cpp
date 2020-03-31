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
    int getDecimalValue(ListNode* head) {
        int re=0;
        ListNode*p=head;
        while(p!=NULL){
            re=re*2+p->val;
            p=p->next;
        }
        return re;

    }
};