class Solution {
public:
    int uniquePaths(int m, int n) {
        // C m-1 m+n-2
        long ans = 1;
        for(int i = m - 2; i >= 0; i--){
            ans *= (m + n - 2 - i);
            ans /= (m - 1 - i);
        }
        return ans;
    }
};