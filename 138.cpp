#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        vector<Node*> v;
        unordered_map<Node*,int> hash;
        int order=1;
        Node* h=head;
        while(head){
            Node* ln=new Node(head->val);
            v.push_back(ln);
            hash.insert({head,order});
            head=head->next;
            order++;
        }
        head=h;
        for(int i=0;i<v.size();i++){
            if(i<v.size()-1) v[i]->next=v[i+1];
            if(!head->random); 
            else{
                auto it=hash.find(head->random);
                int index=it->second;
                v[i]->random=v[index-1];
            }
            head=head->next;
        }
        return v[0];
    }
};