#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));
        int left=0;
        int top=0;
        int right=n-1;
        int down=n-1;
        int m=1;
        while(left<=right||top<=down){
              for(int i=left;i<=right;i++){
                v[top][i]=m++;
              }
              for(int i=top+1;i<=down;i++){
                v[i][right]=m++;
              }
              for(int i=right-1;i>=left;i--){
                v[down][i]=m++;
              }
              for(int i=down-1;i>=top+1;i--){
                v[i][left]=m++;
              }
              top++;
              left++;
              right--;
              down--;
        }
        return v;
    }
};