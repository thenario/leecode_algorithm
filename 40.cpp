#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        traceback(target,result,0,vector<int>(),candidates);
        return result;
    }
    void traceback(int target,vector<vector<int>> &result,int index,vector<int>tp,vector<int> tq){
        if(target==0){
            result.push_back(tp);
            return;
        }
        else if(index>=tq.size()||target<0){
            return;
        }
        for(int i=index;i<tq.size();i++){
            if(i>index&&tq[i]==tq[i-1]) continue;
            int k=target-tq[i];
            tp.push_back(tq[i]);
            traceback(k,result,i+1,tp,tq);
            tp.pop_back();
        }
    }
};