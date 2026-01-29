#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        
        int m=v.size();
        int n=v[0].size();
        if(v[0][0]==1) return 0;
        for(int i=0;i<m;i++){
            if(v[i][0]==0) v[i][0]=1;
            else if(v[i][0]==1){
                for(int j=i;j<m;j++){
                    v[j][0]=0;
                }
                break;
            }
            
        }
        for(int i=1;i<n;i++){
            if(v[0][i]==0) v[0][i]=1;
            else if(v[0][i]==1){
                for(int j=i;j<n;j++){
                    v[0][j]=0;
                }
                 break;
            }
           
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(v[i][j]==1) v[i][j]=0;
                else v[i][j]=v[i][j-1]+v[i-1][j];
            }
        }
        return v[m-1][n-1];
    }
};