class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.length();
        int b = s2.length();
        int c = s3.length();
        if(a + b != c)
            return false;
        // vector<vector<bool>> dp(a + 1, vector<bool>(b + 1, false));
        // dp[0][0] = true;
        vector<bool> dp(b + 1, false);
        dp[0] = true;
        for(int i = 0; i <= a; i++){
            for(int j = 0; j <= b; j++){
                if(i > 0){
                    // dp[i][j] = dp[i][j] || dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                    dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
                }
                if(j > 0){
                    // dp[i][j] = dp[i][j] || dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                    dp[j] = dp[j] || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        // return dp[a][b];
        return dp[b];
    }
};