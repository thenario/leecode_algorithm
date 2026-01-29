#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        int left=0;
        int right=v.size()-1;
        int mid=(left+right)/2;
        while(left<right){
            mid=(left+right)/2;
            if(v[mid]==target){
                return mid;
            }
            else if(v[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            
        }
        if(v[left]>=target) return left;
        else return left+1;
    }
};