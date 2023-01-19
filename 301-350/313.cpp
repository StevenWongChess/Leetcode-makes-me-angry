class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<long> ans(n);
        ans[0] = 1;
        vector<int> dp(m, 0);
        for(int i = 1; i < n; ++i){
            long minv = LONG_MAX;
            for(int j = 0; j < m; ++j){
                minv = min(minv, ans[dp[j]] * primes[j]);
            }
            ans[i] = minv;
            for(int j = 0; j < m; ++j){
                if(ans[dp[j]] * primes[j] == minv){
                    ++dp[j];
                }
            }
        }
        return static_cast<int>(ans[n - 1]);
    }
};