#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int left=0;
        int size=v.size();
        int counter=0;
        while(left<size){
            if(v[left]==k) counter++;
        
                int sum=v[left];
                for(int right=left+1;right<size;right++){
                    sum+=v[right];
                    if(sum==k) {
                        counter++;
                    }
                }
            
            left++;
        }
        return counter;
    }
};