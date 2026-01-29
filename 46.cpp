#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>>res;
        for(int i=0;i<v.size();i++){
            vector<int> t;
            t.push_back(v[i]);
            res.push_back(t);
        }
        for(int i=1;i<v.size();i++){
            vector<vector<int>> temp;
            for(auto &j:res){
                for(int k=0;k<v.size();k++){
                    if(find(j.begin(),j.end(),v[k])==j.end()){
                       vector<int> newPerm = j;  
                        newPerm.push_back(v[k]);
                        temp.push_back(newPerm);
                    }
                }
            }
            res=temp;
        }
        return res;
    }
};