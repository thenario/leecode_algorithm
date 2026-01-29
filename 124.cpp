#include<iostream>
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
    int max_sum=INT_MIN;
    public:
    int maxPathSum(TreeNode* root) {
        tb_max(root);
        set_max(root);
        return max_sum;
    }
    void tb_max(TreeNode* root)
    {
        if(!root) return;
        tb_max(root->left);
        tb_max(root->right);
        if(root->left&&!root->right)
        {
            root->val=root->val>(root->val+root->left->val)?root->val:(root->val+root->left->val);
        }
        if(root->right&&!root->left)
        {
            root->val=root->val>(root->val+root->right->val)?root->val:(root->val+root->right->val);
        }
        if(root->left&&root->right)
        {
            int max=root->right->val>root->left->val?root->right->val:root->left->val;
            if(max>0) root->val=root->val+max;
        }
    }
    void set_max(TreeNode*root)
    {
        if(!root) return;
        set_max(root->left);
        set_max(root->right);
        if(root->left&&root->right)
        {
            if(root->left->val<0&&root->right->val<0)
            {
                max_sum=max_sum>root->val?max_sum:root->val;
            }
            else if((root->left->val>=0&&root->right->val<0)||(root->left->val<0&&root->right->val>=0))
            {
                max_sum=max_sum>root->val?max_sum:root->val;
            }
            else
            {
                int min=root->left->val<root->right->val?root->left->val:root->right->val;
                max_sum=max_sum>(root->val+min)?max_sum:root->val+min;
            }
        }
        else
        {
            max_sum=max_sum>root->val?max_sum:root->val;
        }
    }
};