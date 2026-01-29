#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        int totalLeft = (m + n + 1) / 2;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = totalLeft - i;

            if (i > 0 && j < n && nums1[i - 1] > nums2[j]) {
                high = i - 1;
            }
            else if (j > 0 && i < m && nums2[j - 1] > nums1[i]) {
                low = i + 1;
            }
            else {
                int leftMax;
                if (i == 0) {
                    leftMax = nums2[j - 1];
                }
                else if (j == 0) {
                    leftMax = nums1[i - 1];
                }
                else {
                    leftMax = max(nums1[i - 1], nums2[j - 1]);
                }

                if ((m + n) % 2 == 1) {
                    return leftMax;
                }

                int rightMin;
                if (i == m) {
                    rightMin = nums2[j];
                }
                else if (j == n) {
                    rightMin = nums1[i];
                }
                else {
                    rightMin = min(nums1[i], nums2[j]);
                }

                return (leftMax + rightMin) / 2.0;
            }
        }
        return 0.0;
    }
};