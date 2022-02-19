class Solution {
public:
    vector<vector<string>> ans;
    vector<string> line;
    void dfs(string s, int ith, vector<vector<bool>>& dp){
        if(ith == s.length()){
            ans.push_back(line);
            return;
        }
        for(int i = 0; i + ith < s.length(); i++){
            if(dp[ith][i + ith]){
                line.push_back(s.substr(ith, i + 1));
                dfs(s, i + ith + 1, dp);
                line.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            for(int j = 1; i + j < n && i - j >= 0; j++){
                dp[i - j][i + j] = dp[i - j + 1][i + j - 1] && s[i - j] == s[i + j];
            }
            if(i < n - 1){
                dp[i][i + 1] = (s[i] == s[i + 1]);
                for(int j = 1; i + 1 + j < n && i - j >= 0; j++){
                    dp[i - j][i + 1 + j] = dp[i - j + 1][i + j] && s[i - j] == s[i + 1 + j];
                }
            }
        }
        dfs(s, 0, dp);
        return ans;
    }
};