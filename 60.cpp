#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n);
        vector<int> res;
       for(int i=1;i<=n;i++)
       {
        v[i-1]=i;
       }
        tb(n,k,res,v);
        string s="";
        for(int a:res){
            s+=to_string(a);
        }
        return s;
    }
    void tb(int n,int k,vector<int> &res,vector<int> &tem){
        if(n==0){
            return;
        }
        int m=k/(A(n-1));
        int t=k%(A(n-1));
        if(t==0){
            res.push_back(tem[m-1]);
            tem.erase(tem.begin()+m-1);
            for(int i=tem.size()-1;i>=0;i--){
                res.push_back(tem[i]);
            }
            return;
        }
        else{res.push_back(tem[m]); tem.erase(tem.begin()+m);}
        tb(n-1,t,res,tem);
    }
    
    int A(int t){
        if(t==0) return 1;
        if(t==1) return 1;
        else return A(t-1)*t;
    }
};