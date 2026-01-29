#include<iostream>
#include<algorithm>
#include<stack>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;


        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }

        if (len < k) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        stack<ListNode*> st;


        for (int i = 0; i < len / k; i++) {
            ListNode* groupStart = prev->next;
            ListNode* currNode = groupStart;


            for (int j = 0; j < k; j++) {
                st.push(currNode);
                currNode = currNode->next;
            }


            ListNode* nextGroup = currNode;
            ListNode* current = prev;

            while (!st.empty()) {
                current->next = st.top();
                st.pop();
                current = current->next;
            }


            current->next = nextGroup;
            prev = current;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};