#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string segment;
        

        while (getline(ss, segment, '/')) {

            if (segment.empty() || segment == ".") {
                continue;
            }

            else if (segment == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }

            else {
                stack.push_back(segment);
            }
        }
        

        if (stack.empty()) {
            return "/";
        }
        
        string result;
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        return result;
    }
};