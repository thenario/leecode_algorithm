#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int max=INT_MIN;
        int size=v.size();
        vector<int> dp(size);
        dp[0]=v[0];
        for(int i=1;i<size;i++){
            if(dp[i-1]<=0) dp[i]=v[i];
            else dp[i]=v[i]+dp[i-1];
        }
        return *max_element(dp.begin(),dp.end());
    }
};