#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n);
        int r = 0;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (nums1[i] >= nums2[j]) {
                res[r++] = nums2[j];
                j++;
            }
            else {
                res[r++] = nums1[i];
                i++;
            }
        }
        while (i < m) {
            res[r++] = nums1[i];
            i++;
        }
        while (j < n) {
            res[r++] = nums2[j];
            j++;
        }
        nums1=res;
    }
    
};
    
