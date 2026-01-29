#include<iostream>
#include<vector>
#include<unordered_set>
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
        unordered_set<int> hash;
        vector<int> already;
        ListNode*h=head;
        while(h!=nullptr){
            if(hash.find(h->val)!=hash.end()){
                already.emplace_back(h->val);
            }
            else{
                hash.insert(h->val);            
            }
            h=h->next;
        }
        h=head;
        ListNode* m=new ListNode;
        ListNode* n=m;
        while(h!=nullptr){
            if(find(already.begin(),already.end(),h->val)!=already.end()){
                h=h->next;
            }
            else{
                m->next=h;
                m=m->next;
                h=h->next;
            }
        }
        m->next=nullptr;
        return n->next;
    }
    
};