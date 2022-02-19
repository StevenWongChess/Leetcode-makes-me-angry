class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // for(int i = 0; i < 32; i++){
        while(n){
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};