#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            else return -dividend;
        }

        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long res = 0;

        for (int i = 31; i >= 0; i--) {
            if (a >= (b << i)) {
                a -= (b << i);
                res += (1LL << i);
            }
        }

        if (sign == -1) res = -res;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return res;
    }
};