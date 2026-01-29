#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode*k=new ListNode;
        k->next=head;
        while(head){
            int m=head->val;
            int n=m;
            ListNode* c=head->next;
            ListNode* t=nullptr;
            while(c){
                if(c->val<n){
                    n=c->val;
                    t=c;
                }
                c=c->next;
            }
            if(t){
                head->val=n;
                t->val=m;
            }
            head=head->next;
        }
        return k->next;
    }
};