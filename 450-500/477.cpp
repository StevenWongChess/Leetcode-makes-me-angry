class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(32, 0);
        for(auto j: nums){
            int tmp = j;
            for(int i = 0; i < 32; ++i){
                dp[i] += (tmp & 1);
                tmp >>= 1;
            }
        }
        
        int ans = 0;
        for(auto i: dp){
            ans += i * (n - i);
        }
        
        return ans;
    }
};