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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        tb(res,root);
        return res;
    }
    void tb(vector<int>& res,TreeNode*node){
        if(node->left) tb(res,node->left);
        res.push_back(node->val);
        if(node->right) tb(res,node->right);
    }
};