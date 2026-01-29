#include<iostream>
#include<vector>
#include<algorithm>
#include<climits> // ”√”⁄INT_MAX
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        if (nums.size() < 3) {
            return 0; 
        }

        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2]; 
        int minDiff = abs(closestSum - target);

    
        for (int i = 0; i < nums.size() - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);


                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }


                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {

                    return sum;
                }
            }
        }

        return closestSum;
    }
};

