class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 0)
                    dp[i][j] = p[j - 1] == '*' && dp[i][j - 1];
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = ((p[j - 1] == '?') || (s[i - 1] == p[j - 1])) && dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};