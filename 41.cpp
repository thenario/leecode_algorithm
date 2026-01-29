#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size=100003;
        bool flag=false;    
       
        bitset<100003> bs;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && nums[i]<size){
                bs.set(nums[i]);
            }
        }
        int res;
        for(int i=1;i<size;i++){
            if(!bs.test(i)){
                res=i;
                break;
            }
        }   
        return res;
    }  
};