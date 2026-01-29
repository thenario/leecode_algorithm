#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        int t=1;
        tb(n,t,k,temp,res);
        return res;
    }
    void tb(int k,int i,int m,vector<int> &temp,vector<vector<int>> &res){
        if(m==0) {
            res.push_back(temp);
            return;
        }
        for(int j=i;j<=k;j++){
            temp.push_back(j);
            tb(k,j+1,m-1,temp,res);
            temp.pop_back();
        }
    }
};