#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = { "" };

        for (int i = 0; i < 2 * n; i++) {
            vector<string> tmp;
            for (auto s : res) {

                int open_count = 0, close_count = 0;
                for (char c : s) {
                    if (c == '(') open_count++;
                    else close_count++;
                }


                if (open_count < n) {
                    string new_str = s + "(";
                    tmp.push_back(new_str);
                }


                if (close_count < open_count) {
                    string new_str = s + ")";
                    tmp.push_back(new_str);
                }
            }
            res = tmp;
        }
        return res;
    }
}; 