#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> que;
        int num=1;
        que.push(root);
        while(!que.empty()){
            int temp_num=0;
            res.push_back(que.back()->val);
            while(num){
                num--;
                TreeNode*node=que.front();
                que.pop();
                if(node->left) {
                    que.push(node->left);
                    temp_num++;
               }
               if(node->right){
                que.push(node->right);
                temp_num++;
               }
        }
        num=temp_num;
        }
        return res;
    }
};