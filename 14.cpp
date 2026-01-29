#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    for (int i = 0; i < strs[0].size(); i++) {
    bool flag = true;
    for (int j = 1; j < strs.size(); j++) {
        if (strs[0][i] != strs[j][i])
        {
            flag = false;
            break;
        }
    }
        if(flag)
        res += strs[0][i];
        else
        break;
    }
    return res;
    }
};
