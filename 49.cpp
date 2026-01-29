#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int> hash;
        vector<vector<string>> res;
        int counter=0;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(strs[i].begin(),strs[i].end());
            if(hash.find(strs[i])==hash.end()){
                hash.insert({strs[i],counter});
                counter++;
                vector<string> t;
                t.push_back(s);
                res.push_back(t);
            }
            else {
                auto it=hash.find(strs[i]);
                res[it->second].push_back(s);
            }
        }
        hash.clear();
        return res;
    }
};