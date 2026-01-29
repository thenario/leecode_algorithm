#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zerosum=0;
        int size=nums.size();
        int i=0;
        int j=0;
        while(i<size){
            if(nums[i]==0){
                zerosum++;
            }
            else{
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        for(int m=0;m<zerosum;m++){
            nums[j+m]=0;
        }
    }
};