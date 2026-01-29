#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star_idx = -1;  
        int match = 0;      
        
        while (i < s.length()) {

            if (j < p.length() && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }
           else if (j < p.length() && p[j] == '*') {
                star_idx = j;
                match = i;
                j++;
            }

            else if (star_idx != -1) {
                j = star_idx + 1;
                match++;
                i = match;
            }

            else {
                return false;
            }
        }
        

        while (j < p.length() && p[j] == '*') {
            j++;
        }
        
        return j == p.length();
    }
};