#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& s, int target) {
        int left=0,right=s.size()-1;
        int mid=left+(right-left)/2;
        while(s[mid]!=target&&left<=right){
            if(s[mid]<target){
                left=mid+1;
                mid=left+(right-left)/2;
            }
            else if(s[right]>target){
                right=mid-1;
                mid=left+(right-left)/2;
            }
        }
        if(s[mid]!=target){
            return {-1,-1};
        }
        else if(s[mid]==target){
             left=mid;
             right=mid;
            while(left>0&&s[left]==target){
                left--; 
            }
            if(s[left]!=target) left++;
            while(right<s.size()-1&&s[right]==target){
                right++; 
            }
            if(s[right]!=target) right--;
            
        }
        return{left,right};
    } 
};
int main() {
    vector<int>nums = {5,7,7,8,8,10};int target = 8;
    vector<int>res=Solution().searchRange(nums,target);
    cout<<res[0]<<" "<<res[1];
    return 0;
}
