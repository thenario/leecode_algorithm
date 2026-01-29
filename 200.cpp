#include <vector>
using namespace std;

class Solution {
public:
        int count = 0;
        
        // DFS 函数
    void dfs(int i, int j,vector<vector<char>>& grid) {
            // 越界检查或遇到水
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
                return;
            }
            

            grid[i][j] = '0';
            

            dfs(i + 1, j,grid);
            dfs(i - 1, j,grid);
            dfs(i, j + 1,grid);
            dfs(i, j - 1,grid);
        };
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(i, j,grid);
                }
            }
        }
        
        return count;
    }
};