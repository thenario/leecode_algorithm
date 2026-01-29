#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) {
            return res;
        }
        for (int i = 0; i < nums.size()-3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) { 
                    long tag=long(target)-nums[i]-nums[j];
                    if (tag == nums[left] + nums[right]) {
                        res.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        while (left<right&&nums[left] == nums[left + 1]) left++;
                        while (right>left&&nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                    else if (tag > nums[left] + nums[right]) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
