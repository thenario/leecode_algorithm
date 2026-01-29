#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* res = new ListNode;
        res->next = head->next;
        while (head && head->next && head->next->next && head->next->next->next) {
            ListNode* tem1 = head->next;
            ListNode* tem2 = head->next->next;
            head->next = tem2->next;
            tem1->next = head;
            head = tem2;
       }
      
        if (!head->next->next) {
            ListNode* tem = head->next;
            head->next = nullptr;
            tem->next = head;
            
        }
        else if (!head->next->next->next) {
            ListNode* tem = head->next;
            head->next = tem->next;
            tem->next = head;
           
        }
        return res->next;
    }
};