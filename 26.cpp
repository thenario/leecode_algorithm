#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res;
        int slow = 0;
        int fast = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (find(res.begin(), res.end(), nums[fast]) != res.end()) {
                continue;
            }
            else {
                nums[slow] = nums[fast];
                slow++;
                res.push_back(nums[fast]);
            }
        }
        return slow;
    }
};