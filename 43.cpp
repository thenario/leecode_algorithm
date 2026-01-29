#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size(), n = num2.size();

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> res(m + n, 0);
        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int mul = (num1[i] - '0') * (num2[j] - '0');

                res[i + j] += mul;

                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
        int end = m + n - 1;
        while (end >= 0 && res[end] == 0) {
            end--;
        }
        string ans;
        for (; end >= 0; end--) {
            ans += to_string(res[end]);
        }
        
        return ans;
    }
};