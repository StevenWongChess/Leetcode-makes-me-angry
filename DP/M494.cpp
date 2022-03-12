class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }
        if(sum < abs(target))
            return 0;
        vector<int> v(2 * sum + 1, 0);
        v[sum + nums[0]]++; v[sum - nums[0]]++; 
        for(int i = 1; i < nums.size(); i++){
            vector<int> tmp(2 * sum + 1, 0);
            for(int j = 0; j < 2 * sum + 1; j++){
                tmp[j] = ((j + nums[i] < 2 * sum + 1) ? v[j + nums[i]] : 0) + 
                        ((j - nums[i] >= 0) ? v[j - nums[i]] : 0);
            }
            v.swap(tmp);
        }
        return v[sum + target];
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }
        int diff = sum - target;
        if(diff < 0 || diff % 2 != 0)
            return 0;
        vector<int> dp(diff / 2 + 1, 0);
        dp[0] = 1;
        for(auto i: nums){
            for(int j = diff / 2; j >= i; j--){
                dp[j] += dp[j - i];
            }
        }
        return dp[diff / 2];
    }
};