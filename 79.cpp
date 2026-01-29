#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(backtrack(board, word, visited, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
private:
    bool backtrack(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int index) {

        if(index == word.length()) {
            return true;
        }
        

        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || 
           visited[i][j] || board[i][j] != word[index]) {
            return false;
        }
        
   
        visited[i][j] = true;
        
   
        bool found = backtrack(board, word, visited, i + 1, j, index + 1) ||
                     backtrack(board, word, visited, i - 1, j, index + 1) ||
                     backtrack(board, word, visited, i, j + 1, index + 1) ||
                     backtrack(board, word, visited, i, j - 1, index + 1);
        

        visited[i][j] = false;
        
        return found;
    }
};