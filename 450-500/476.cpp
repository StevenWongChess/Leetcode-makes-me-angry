class Solution {
public:
    int findComplement(int num) {
        int digits = 0, tmp = num;
        while(tmp){
            ++digits;
            tmp >>= 1;
        }
        int mask = (digits == 31) ? 0x7fffffff : ((1 << digits) - 1);
        return num ^ mask;
    }
};