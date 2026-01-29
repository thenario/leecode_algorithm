#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> res;
        tb(root,res);
        for(int i=0;i<res.size();i++){
            if(i==res.size()-1){
                res[i]->left=nullptr;
                break;
            }
            res[i]->left=nullptr;
            res[i]->right=res[i+1];
        }
    }
    void tb(TreeNode* node,vector<TreeNode*>& res){
        res.push_back(node);
        if(node->left) tb(node->left,res);        
        if(node->right) tb(node->right,res);        
    }
};