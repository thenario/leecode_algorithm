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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* tem=new ListNode;
        tem->next=head;
        ListNode* pl=nullptr;
        ListNode* pr=nullptr;
        ListNode* pm=nullptr;
      
        for(int i=1;i<=right;i++){
            if(i==left-1) pm=head;
            if(i==left) pl=head;
            if(i==right) pr=head;
            head=head->next;
        }
        while(pl!=pr){
            ListNode* m=pl->next;
            pl->next=pr->next;
            pr->next=pl;
            pl=m;
        }
        if(pm) {
            pm->next=pr;
        }
        else if(!pm){
            tem->next=pr;
        }
;
        return tem->next;
    }
};