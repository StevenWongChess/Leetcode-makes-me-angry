class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while(left < right){
            int mid = ((right - left) >> 1) +left;
            if((long long) mid * mid == x)
                return mid;
            else if((long long) mid * mid < x)
                left = mid + 1;
            else    
                right = mid;
        }
        return (long long)left * left == x ? left : left - 1;
    }
};