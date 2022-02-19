class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n){
            return 0;
        }
        // vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        // for(int i = 0; i <= m; i++){
        //     dp[i][0] = 1;
        // }
        for(int i = 1; i <= m; i++){
            // for(int j = 1; j <= n; j++){
            for(int j = n; j >= 1; j--){
                dp[j] = (s[i - 1] == t[j - 1]) ? dp[j - 1] + dp[j] : dp[j];
                if(dp[j] > INT_MAX)
                    dp[j] = 0;
                // dp[i][j] = (s[i - 1] == t[j - 1]) ? dp[i-1][j-1] + dp[i - 1][j] : dp[i - 1][j];
                // if(dp[i][j] > INT_MAX)
                //     dp[i][j] = 0;
            }
        }
        // return dp[m][n];
        return dp[n];
    }
};