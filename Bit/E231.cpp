class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && ((n & (n - 1)) == 0);
        // while(n > 1){
        //     if(n % 2 == 1)
        //         return false;
        //     n >>= 1;
        // }
        // return n == 1;
    }
};