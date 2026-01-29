#include<iostream>
#include<vector>
#include<unordered_map>
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
private:
    unordered_map<int, int> inorder_map;
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) 
            return nullptr;
        

        for(int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, 
                   int preStart, int preEnd, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        

        TreeNode* root = new TreeNode(preorder[preStart]);
        

        int rootIndex = inorder_map[preorder[preStart]];

        int leftSize = rootIndex - inStart;

        root->left = build(preorder, inorder, 
                          preStart + 1, preStart + leftSize,
                          inStart, rootIndex - 1);

        root->right = build(preorder, inorder,
                           preStart + leftSize + 1, preEnd,
                           rootIndex + 1, inEnd);
        
        return root;
    }
};