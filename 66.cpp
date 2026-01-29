#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=digits.size();
        int next=1;
        int current=0;
        for(int i=size-1;i>=0;i--){
            current=(digits[i]+next)%10;
            next=(digits[i]+next)/10;
            digits[i]=current;
        }
        if(next==0) return digits;
        vector<int> res(1,1);
        res.insert(res.end(),digits.begin(),digits.end());
        return res;
    }
};