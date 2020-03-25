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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        if(lists.size()==1) return lists[0];
        ListNode *st=lists[0];
        for (int i = 1; i < lists.size(); ++i)
        {
            st=mergeTwoList(st,lists[i]);
        }
        return st;
    }
    ListNode* mergeTwoList(ListNode *l1,ListNode *l2){
        ListNode *p=l1,*q=l2,*rear,*tmp;
        ListNode *rt=new ListNode(-1);
        rear=rt;
        while(p!=NULL&&q!=NULL){
            if(p->val<=q->val){
                tmp=p;
                p=p->next;
            }else if (p->val>q->val)
            {
                tmp=q;
                q=q->next;
            }
            rear->next=tmp;
            rear=rear->next;
        }
        if(p!=NULL)rear->next=p;
        if(q!=NULL)rear->next=q;
        return rt->next;
    }
};