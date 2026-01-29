#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        v.insert(v.end(),intervals.begin(),intervals.end());
        v.push_back(newInterval);
        
        vector<vector<int>>res= merge(v);
        return res;
    }
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        

        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
      
            if (intervals[i][0] <= res.back()[1]) {
        
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
   
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};