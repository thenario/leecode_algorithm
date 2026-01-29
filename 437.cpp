#include<iostream>
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
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        unordered_map<long, int> prefixSumCount; 
        prefixSumCount[0] = 1; 
        
        return dfs(root, 0, targetSum, prefixSumCount);
    }
    
private:
    int dfs(TreeNode* node, long currentSum, int target, unordered_map<long, int>& prefixSumCount) {
        if (!node) return 0;
        
        currentSum += node->val; 
        int count = prefixSumCount[currentSum - target];
        
        prefixSumCount[currentSum]++;
        count += dfs(node->left, currentSum, target, prefixSumCount);
        count += dfs(node->right, currentSum, target, prefixSumCount);
        prefixSumCount[currentSum]--;
        
        return count;
    }
};