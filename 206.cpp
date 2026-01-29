#include<iostream>
#include<stack>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> q;
        while(head){
            q.push(head);
            head=head->next;
        }
        if(q.empty()) return nullptr;
        ListNode* m=new ListNode(0);
        head=q.top();
        while(!q.empty()){
            m->next=q.top();
            q.pop();
            m=m->next;
        }
        m->next=nullptr;
        return head;
    }
};