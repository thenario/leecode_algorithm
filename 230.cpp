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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        tb(res,root);
        return res[k-1];
    }
    void tb(vector<int>& v,TreeNode*node){
        if(node->left) tb(v,node->left);
        v.push_back(node->val);
        if(node->right) tb(v,node->right);
    }
};