#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> result = { "" };

        for (char digit : digits) {
            vector<string> temp;
            for (const string& s : result) {
                for (char c : mapping[digit]) {
                    temp.push_back(s + c);
                }
            }
            result = temp;
        }

        return result;
    }
};