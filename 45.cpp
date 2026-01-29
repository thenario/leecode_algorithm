#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int step=0;
        int index=0;
        int res=0;
        traceback(nums,step,index,res);
        return res;
    }
    void traceback(vector<int>&v,int step,int index,int &res){
        step+=1;
        int sum=v[index]+index;
        if(sum>=v.size()-1){
            res=step;
            return;
        }
        else{
            int max=v[index+1]+index;
            int j=index+1;
            for(int i=index+1;i<v.size()&&i<index+1+v[index];i++){
                if(i+v[i]>=max){
                    j=i;
                    max=v[i]+i;
                }
            }
            traceback(v,step,j,res);
        }
    }
};