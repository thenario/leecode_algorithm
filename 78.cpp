#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        for(int i=0;i<=nums.size();i++){
            tb(0,i,temp,res,nums);
        }
        return res;
    }
    void tb(int i,int m,vector<int> &temp,vector<vector<int>> &res,vector<int> nums){
        if(m==0) {
            res.push_back(temp);
            return;
        }
        for(int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            tb(j+1,m-1,temp,res,nums);
            temp.pop_back();
        }
    }
};