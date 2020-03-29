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
    ListNode* swapPairs(ListNode* head) {
    int k=2;
        vector<ListNode*> v;
        ListNode*p=head,*q=head,*tmp;
        while(p!=NULL){
            int cnt=0;
            ListNode* st=p;
            while(cnt<k-1&&p!=NULL){
                p=p->next;
                cnt++;
            }
            if(p==NULL){
                v.push_back(st);
                break;
            }
            tmp=p->next;
            p->next=NULL;
            v.push_back(st);
            p=tmp;
        }
        ListNode *rt=new ListNode(0);
        ListNode *rear=rt;
        for (int i = 0; i < v.size(); ++i)
        {
            if (Listlen(v[i])==k)
            {
                rear->next=reverseList(v[i]);
                while(rear->next!=NULL)rear=rear->next;
            }else{
                rear->next=v[i];
                while(rear->next!=NULL)rear=rear->next;
            }
        }
        return rt->next;
    }
    int  Listlen(ListNode* head){
        if(head==NULL)return 0;
        int cnt=1;
        while(head->next!=NULL){
            head=head->next;
            cnt++;
        }
        return cnt;
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