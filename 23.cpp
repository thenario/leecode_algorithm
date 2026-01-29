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
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         lists.erase(remove_if(lists.begin(), lists.end(), [](ListNode* a) {return a == nullptr; }),lists.end());
         if (lists.empty()) return nullptr;
         ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while (!lists.empty()) {
            auto iter = max_element(lists.begin(), lists.end(), [](ListNode* a, ListNode* b) {return a->val > b->val; });
            cur->next = *iter;
            cur = cur->next;
            *iter = (*iter)->next;
            if (*iter == nullptr) {
                lists.erase(iter);

            }


        }
        return head->next;
    }
};
