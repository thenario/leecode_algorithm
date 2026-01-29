#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> hash;
        int row,col;
        row=board.size();
        col=board[0].size();
        bool flag=true;
        for(int i=0;i<row;i++){
            hash.clear();
            for(int j=0;j<col;j++){
                if(isdigit(board[i][j])&&hash.find(board[i][j])!=hash.end()){
                    flag=false;
                    return flag;
                }
                else if(isdigit(board[i][j])&&hash.find(board[i][j])==hash.end()){
                    hash[board[i][j]]=1;
                }
            }
            
        }
        for(int i=0;i<row;i++){
            hash.clear();
            for(int j=0;j<col;j++){
                if(isdigit(board[j][i])&&hash.find(board[j][i])!=hash.end()){
                    flag=false;
                    return flag;
                }
                else if(isdigit(board[j][i])&&hash.find(board[j][i])==hash.end()){
                    hash[board[j][i]]=1;
                }
            }
            
        }
        hash.clear();
        for(int i=0;i<row;i+=3){
            for(int j=0;j<col;j+=3){
                hash.clear();
               for(int k=i;k<i+3;k++) {
                for(int l=j;l<j+3;l++){ 
                    if(isdigit(board[k][l])&&hash.find(board[k][l])!=hash.end()){
                        flag=false;
                        return flag;
                    }
                    else if(isdigit(board[k][l])&&hash.find(board[k][l])==hash.end()){
                        hash[board[k][l]]=1;
                    }
                }
               }
            }
        }
        return flag;
    }
};