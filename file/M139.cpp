class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for(auto i: wordDict){
            dict[i] = true;
        }
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()){
                    dp[i] = true; break;
                }
            }
        }
        return dp[n];
    }
};