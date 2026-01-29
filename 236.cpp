#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        while(root){
            if(find_tn(root->left,p)&&find_tn(root->left,q)) 
            {
                root=root->left;
                continue;
            }    
            else if(find_tn(root->right,p)&&find_tn(root->right,q)) 
            {
                root=root->right;
                continue;
            }
            else  return root;
            
        }
        return nullptr;
    }
    bool find_tn(TreeNode* root,TreeNode* target)
    {
        if(!root) return false;
        if(root==target) return true;
        else return find_tn(root->left,target)||find_tn(root->right,target);    
    }
};