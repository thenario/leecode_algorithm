#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        bool isNegative = false;

        while (i < n && s[i] == ' ') {
            i++;
        }


        if (i >= n) {
            return 0;
        }

  
        if (s[i] == '-') {
            isNegative = true;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        long long result = 0; 


        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;

  
            if (isNegative && -result < INT_MIN) {
                return INT_MIN;
            }
            if (!isNegative && result > INT_MAX) {
                return INT_MAX;
            }

            i++;
        }

        if (isNegative) {
            result = -result;
        }

     
      

        return (int)result;
    }
};
