#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int max=INT_MIN;
        vector<int>v;
        int length=0;
        bool isin=(s[0]==' ')?false:true;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '||i==s.size()-1){
                if(i==s.size()-1&&s[i]!=' '){ 
                    length++;
                    if(!isin) isin=!isin;
                }
                if(isin) v.push_back(length);
                length=0;
                if(isin) isin=false;
            }
            else {
                length++;
                if(!isin) isin=true;
            }
        }
        if(v.empty()){
            return 0;
        }   
        return v.back();
    }
};