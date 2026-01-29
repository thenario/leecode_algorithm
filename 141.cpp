#include<iostream>
#include<unordered_set>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        while(head){
            if(hash.find(head)!=hash.end()){
                return true;
            }
            hash.insert(head);
            head=head->next;
        }
        return false;
    }
};