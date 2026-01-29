#include<iostream>
#include<algorithm> 
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*h=new ListNode;
        h=head;
        while(head!=nullptr){
                while(head->next&&head->next->val==head->val){
                        ListNode*m=head->next;
                        head->next=head->next->next;
                        delete m;
                }
                head=head->next;
        }
        return h;
    }
};