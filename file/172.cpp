class Solution {
public:
    int trailingZeroes(int n) {
        int count = 5;
        int ans = 0;
        while(count <= n){
            ans += (n / count);
            count *= 5;
        }
        return ans;
    }
};