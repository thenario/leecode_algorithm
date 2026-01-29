#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left=1;
        int right=m*n;
        while(left<=right)
        {
            int pos=(left+right)/2;
            int col=pos%n-1;
            int row=pos/n;
            if(col==-1){
                col=n-1;
                row=row-1;
            }
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                right=pos-1;
            }
            else{
                left=pos+1;
            }
        }
        return false;
    }
};