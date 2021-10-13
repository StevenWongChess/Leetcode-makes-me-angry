class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m; i < m + n - 1; i++){
            ans =  ans * i / (i - m + 1);
        }
        return ans;
    }
};