class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[0][0] = true;

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                int diff = stones[i] - stones[j];
                if(diff >= n)
                    continue;
                if(dp[j][diff] || dp[j][max(diff - 1, 0)] || dp[j][min(diff + 1, n - 1)]){
                    dp[i][diff] = true;
                    if(i == n - 1){
                        // print(dp);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void print(vector<vector<bool>> v){
        for(auto i: v){
            for(auto j: i){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};