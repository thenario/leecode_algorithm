#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.size();
        int prev1 = 1, prev2 = 1;  
        
        for (int i = 1; i < n; i++) {
            int current = 0;
            

            if (s[i] != '0') {
                current += prev1;
            }
            

            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }
            

            prev2 = prev1;
            prev1 = current;
            if (current == 0) return 0;
        }
        
        return prev1;
    }
};