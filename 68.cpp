#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        
        while (i < n) {

            int j = i;
            int lineLength = 0;

            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            

            int numWords = j - i;
            int totalSpaces = maxWidth - lineLength;
            
            string line;
            

            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += " ";
                    line += words[k];
                }

                line += string(maxWidth - line.length(), ' ');
            } 

            else {
                int baseSpaces = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {

                        int spaces = baseSpaces;
                        if (k - i < extraSpaces) {
                            spaces++;
                        }
                        line += string(spaces, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};