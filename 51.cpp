#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp;
        for(int i=0;i<n;i++){
            string s(n,'.');
            
            temp.push_back(s);
        }
        traceback(0,res,temp);
        return res;
    }
    bool isvalid(vector<string> t){
        int size=t[0].size();
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(t[i][j]=='Q'){
                    for(int k=0;k<size;k++){
                        if((k!=i&&t[k][j]=='Q')||(k!=j&&t[i][k]=='Q')){
                            return false;
                        }
                        int min= i>=j?j:i;
                        int m=i-min;
                        int n=j-min;
                        while(m<size&&n<size){
                            if(m!=i&&n!=j&&t[m][n]=='Q'){
                                return false;
                            }
                            m++;
                            n++;
                        }
                        m=i;
                        n=j;
                          while(m>=0&&n<size){
                            if(m!=i&&n!=j&&t[m][n]=='Q'){
                                return false;
                            }
                            m--;
                            n++;
                        }
                        m=i;
                        n=j;
                          while(m<size&&n>=0){
                            if(m!=i&&n!=j&&t[m][n]=='Q'){
                                return false;
                            }
                            m++;
                            n--;
                        }
                    }

                }
            }
        }
        return true;
    }
    void traceback(int n,vector<vector<string>> &res,vector<string> &temp){
        if(n==temp[0].size()){
            res.push_back(temp);
            return;
        }
        vector<string> f=temp;
        for(int i=0;i<temp[0].size();i++){
            temp[n][i]='Q';
            if(isvalid(temp)){
                traceback(n+1,res,temp);
            }
            temp=f;
        }
    }
};