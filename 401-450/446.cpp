class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long, long>> dp(n);
        int ans = 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                long diff = static_cast<long>(nums[i]) - static_cast<long>(nums[j]);
                ++dp[i][diff];
                
                if(dp[j].count(diff)){
                    ans += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        
        return ans;
    }
};