#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0;
        for(i;i<nums.size()-1;i++){
            if(nums[i]-nums[i+1]<=0){
                continue;
            }
            else{
                break;
            }
        }
        nums.insert(nums.end(),nums.begin(),nums.begin()+i+1);
        nums.erase(nums.begin(),nums.begin()+i+1);
        return tf(target,nums);
    }
    bool tf(int target,vector<int> v){
        int left=0;
        int right=v.size()-1;
        int m=0;
        if(v[left]==target||v[right]==target) return true;
        while(left<=right){
            m=(left+right)/2;            
            if(v[m]==target) return true;
            else if(v[m]>target) right=m-1;
            else left=m+1;
        }
        return false;
    }
};