#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        if (x == INT_MIN) return 0;


        bool isNegative = x < 0;
        if (isNegative) x = -x;

        vector<int> digits;

        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
  


        long long result = 0; 
        for (int digit : digits) {
            result = result * 10 + digit;
 
            if (result > INT_MAX) return 0;
        }


        return isNegative ? -result : result;
    }
};