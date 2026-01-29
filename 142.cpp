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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        while(head){
            if(hash.find(head)!=hash.end()){
                return *(hash.find(head));
            }
            hash.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};