#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string res="";

        if(n==1){
            return "1";
        }
        else if(n==2){
            return "11";
        }
        else if(n==3){
            return "21";
        }
        else if(n==4){
            return "12";
        }
        else{
            string s=countAndSay(n-1);
            int left=0;
            int right=0;
            
            while(left<s.size()&&right<s.size()){
                while(right<s.size()&&s[left]==s[right]){
                    right++;
                }
                res+=to_string(right-left)+s[left];
                left=right;
            }
        }
        return res;
    }
};