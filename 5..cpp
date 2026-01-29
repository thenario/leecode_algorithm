#include<iostream>
#include<vector>
#include<utility>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLength = 1;
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            int len = right - left - 1;
            if (len > maxLength) {
                maxLength = len;
                start = left + 1;
            }
            left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            len = right - left - 1;
            if (len > maxLength) {
                maxLength = len;
                start = left + 1;
            }
        }
        return s.substr(start, maxLength);
    }
};
