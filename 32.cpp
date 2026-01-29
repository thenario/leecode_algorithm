#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int max_len = 0;
        while (left < s.size()) {
            if (s[left] == '(') {
                int num = 0;
                int numl = 0;
                for (int right = left; right < s.size(); right++)
                {
                    if (s[right] == '(') {
                        num++;
                        numl++;
                    }
                    else if (s[right] == ')')
                    {
                        if (numl == 1) {
                            num++;
                            numl--;
                            max_len = max(max_len, num);
                        }
                        else if (numl > 1) {
                            num++;
                            numl--;
                        }
                        else if (numl == 0) {
                            break;
                        }
                    }
                        
                    
                }
            }
            left++;
        }
        return max_len;
    }
};
