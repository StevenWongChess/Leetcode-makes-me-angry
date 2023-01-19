class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1){
            return false;
        }
        
        int m = sum / 2 + 1;
        vector<bool> dp(m, false);
        dp[0] = true;
        
        for(auto i: nums){
            for(int j = m - 1; j >= i; --j){
                if(dp[j - i]){
                    dp[j] = true;
                }
            }
        }
        
        return dp[m - 1];
    }
};