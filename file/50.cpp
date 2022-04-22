class Solution {
public:
    double myPow(double x, int n) {
        double mul = n >= 0 ? x : 1/x;
        n = abs(n);
        double ans = 1;
        while(n){
            if(n & 1)
                ans *= mul;
            mul *= mul;
            n /= 2;
        }
        return ans;
    }
};