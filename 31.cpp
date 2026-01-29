#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& v) {
        vector<int> v1 = v; 
        sort(v1.begin(), v1.end(), [](int a, int b) {return a > b; });
        if (v1 == v) {
            sort(v.begin(), v.end());
            return;
        }
        for (int i = v.size() - 1; i > 0; i--) {
            if (v[i - 1] >= v[i]) {
                continue;
            }
            else if (v[i - 1] < v[i]) {
                if (v.size() - i == 1) {
                    reverse(v.begin() + i - 1, v.end());
                    return;
                }
                else if (v.size() - i > 1) {
                    int tem = INT_MAX;
                    int index = i ;
                    for (int j = i ; j < v.size(); j++) {
                        if (v[j] < tem && v[j] > v[i - 1]) {
                            tem=v[j];
                            index = j;
                        }
                      
                    }
                    v[index] = v[i - 1];
                    v[i - 1] = tem;
                    sort(v.begin() + i, v.end());
                    return;
                }
            }
        }
        
    }
};