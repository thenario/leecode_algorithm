#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1){
            return {0,1};
        }
        else if(n==2){
            return {0,1,3,2};
        }
        else{
            vector<int> v={0,1,3,2};
            while(n>2){
                int size=v.size();
                for(int i=size-1;i>=0;i--){
                    v.push_back(v[i]+size);
                }
                n--;    
            }
            return v;
        }
        return {};
    }
};