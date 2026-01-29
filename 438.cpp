#include<iostream>
#include<vector>
using namespace std;
vector<int> findAnagrams3(string s, string p) {
    vector<int> result;
    if (s.size() < p.size()) return result;
    
    vector<int> target(26, 0);  
    vector<int> window(26, 0);  
    
 
    for (char c : p) {
        target[c - 'a']++;
    }
    
    int left = 0, right = 0;
    int m = s.size(), n = p.size();
    
    while (right < m) {

        window[s[right] - 'a']++;
        right++;

        if (right - left == n) {

            if (window == target) {
                result.push_back(left);
            }
            

            window[s[left] - 'a']--;
            left++;
        }
    }
    
    return result;
}