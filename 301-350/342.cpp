class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && ((n & (n - 1)) == 0) && ((n & 0xAAAAAAAA) == 0);
        // if(n <= 0)
        //     return false;
        // while(n > 1){
        //     if(n % 4 != 0){
        //         return false;
        //     }
        //     n /= 4;
        // }
        // return true;
    }
};