#include<iostream>
#include<limits>
class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(x==0) return 0;
        if(x==-1) return n%2==0?1:-1;
        if(n==0) return 1;
        if(n>0) {
            double res=1;
            for(int i=0;i<n;i++){
                res*=x;
                if (res>0&&res<std::numeric_limits<double>::min()) return 0;
            }
            return res;
        }
        long long b=n;
        b=abs(b);
        double res=1;
        for(int i=0;i<b;i++){
            res*=1/x;
            if (res>0&&res<std::numeric_limits<double>::min()) return 0;
        }
        return res;
    }
 };