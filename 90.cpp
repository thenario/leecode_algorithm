#include<iostream>
#include<vector>
#include<cmath>
#include<bitset>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<pow(2,size);i++){
            bitset<12> bit(i);
            vector<int> temp;
            for(int j=0;j<size;j++){
                if(bit[j]==0){
                    continue;
                }
                if(bit[j]==1){
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            if(find(res.begin(),res.end(),temp)==res.end()) res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};