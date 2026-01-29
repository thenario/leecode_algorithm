#include <iostream>
#include <vector>
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
     ListNode* removeNthFromEnd(ListNode* head, int n) {
         if (head->next == nullptr) {
             return nullptr;
         }

         ListNode* left = head;
         ListNode* right = head;
         while (--n) {
             right = right->next;
         }
         while (right->next && right->next->next) {
             left = left->next;
             right = right->next;
         }
         if (!right->next) {

             left = left->next;

             return left;
         }
         else   {
             ListNode* temp = left;
             left = left->next;
             temp->next = left->next;
             return head;
         }
     }
 
};
