#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }

private:
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if (backtrack(board)) {
                                return true;
                            }
                            board[i][j] = '.'; 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // 检查行
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) {
                return false;
            }
        }
        
        // 检查列
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) {
                return false;
            }
        }
        
        // 检查3x3宫格
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

  