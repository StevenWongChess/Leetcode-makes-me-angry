class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();

        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 1;
        for(int i = m - 1; i >= 0; --i){
            int next = INT_MAX;
            for(int j = n - 1; j >= 0; --j){
                dp[j] = max(min(dp[j], next) - dungeon[i][j], 1);
                next = dp[j];
            }
        }

        return dp[0];
    }
};