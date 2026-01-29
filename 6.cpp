#include<iostream> 
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        if (numRows == 1) {
            return s;
        }
        for (int i = 0; i < s.size(); i++) {
           int t=i%(2*numRows-2);
           if (t >= 0 && t <= numRows - 1) {
               v[t].push_back(s[i]);
           }
           else {
               v[2 * numRows - 2 - t].push_back(s[i]);
           }
           }
        
        string res;
        for (auto i : v) {
            for (auto alpha : i) {
                res += alpha;
            }
        }
        return res;
    }
};
