#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        bool is_in_int=false;
        int size=s.size();
        bool norp=false;
        bool havee=false;
        bool dotted=false;
        for(int i=0;i<size;i++){
            if(s[i]=='-'||s[i]=='+'){
                if(norp) return false;
                norp=true;
                if(is_in_int) return false;
            }
            else if(isdigit(s[i])){
                if(!is_in_int) is_in_int=!is_in_int;
                else continue;
            }
            else if(s[i]=='e'||s[i]=='E'){
                if(havee) return false;
                havee=true;
                if(!is_in_int) return false;
                else {
                    dotted=true;
                    is_in_int=!is_in_int;
                    norp=false;
                }
            }   
            else if(s[i]=='.'){
                if(dotted) return false;
                dotted=true;
                if(i==0){
                    if(size==1) return false;
                    else if(s[i+1]=='e'||s[i+1]=='E') return false;
                    else if(s[i+1]=='-'||s[i+1]=='+'||isdigit(s[i+1])) {
                        is_in_int=true;
                        continue;
                    }
                } 
                else{
                    if(isdigit(s[i-1])){
                        continue;
                    }
                    if(s[i-1]=='+'||s[i-1]=='-'){
                        if(size==2) return false;
                        else {
                            if(s[i+1]=='e'||s[i+1]=='E') return false;
                            else {is_in_int=true;continue;}
                        }
                    }
            }
            }
            else return false;
        }
        if(is_in_int)return true;
        else return false;
    }
};