#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> v1;
        while(headA){
            v1.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(v1.find(headB)!=v1.end()){
                return headB;
            }
            headB=headB->next;
        }
        return nullptr;
    }
};