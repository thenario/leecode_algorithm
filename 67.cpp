#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = 1;
        int asize = a.size();
        int bsize = b.size();
        int current = 0;
        int next = 0;
        
        while (i <= asize && i <= bsize) {
            int numA = a[asize - i] - '0';  
            int numB = b[bsize - i] - '0';  
            current = (numA + numB + next) % 2;
            next = (numA + numB + next) / 2;
            res = to_string(current) + res;
            i++;
        }
        
        while (i <= asize) {
            int numA = a[asize - i] - '0';  
            current = (numA + next) % 2;
            next = (numA + next) / 2;
            res = to_string(current) + res;
            i++;
        }
        
        while (i <= bsize) {
            int numB = b[bsize - i] - '0';  
            current = (numB + next) % 2;
            next = (numB + next) / 2;
            res = to_string(current) + res;
            i++;
        }
        
        if (next == 1) res = "1" + res;
        return res;
    }
};