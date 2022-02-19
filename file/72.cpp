class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m + 1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i < n + 1; i++){
            dp[0][i] = i;
        }
        for(int i = 1; i < m + 1; i++){
            for(int j = 1; j < n + 1; j++){
                int a = dp[i - 1][j] + 1;
                int b = dp[i][j - 1] + 1;
                int c = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
                dp[i][j] = min(a, min(b, c));
            }
        }
        return dp[m][n];
    }
};