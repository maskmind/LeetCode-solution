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
        		ListNode *p=l1,*q=l2,*rear;
		ListNode* num=new ListNode(-1);
		rear=num;
		int tmp=0;
		while(p!=NULL||q!=NULL){
			int sum=tmp;
			if (p!=NULL){
				sum+=p->val;
				p=p->next;
			}
			if (q!=NULL){
				sum+=q->val;
				q=q->next;
			}
			tmp=sum>9? 1: 0; 
			ListNode* n=new ListNode(sum%10);
			rear->next=n;
			rear=rear->next;
		}
		if(tmp==1){
			ListNode* n=new ListNode(1);
			rear->next=n;
		}
		return num->next;
    }
};