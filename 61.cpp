#include<iostream>
#include<vector>
#include<stack>
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* h=head;
        ListNode* t=head;
        ListNode* m=head;
        ListNode* res=head;

        while(head){
            head=head->next;
            n++;
        }
        
        head=h;
        if(!head) return nullptr;
        k%=n;
        if(k==0){
            return head;
        }
        
        for(int i=0;i<n;i++){
            if(i==n-k-1) h=head;
            if(i==n-k) res=head;
            if(i==n-1) t=head;
            head=head->next; 
        }
        h->next=nullptr;
        t->next=m;
        return res;

    }
};