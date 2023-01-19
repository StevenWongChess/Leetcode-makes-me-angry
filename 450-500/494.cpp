class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(target > sum || (sum - target) % 2 == 1){
            return false;
        }
     
        int size = (sum - target) / 2;
        
        vector<int> dp(size + 1);
        dp[0] = 1;
        
        for(auto i: nums){
            for(int j = size; j >= i; --j){
                dp[j] += dp[j - i];
            }
        }
        
        return dp[size];
    }
};