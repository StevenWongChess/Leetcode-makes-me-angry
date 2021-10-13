class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int current = 0;
        for(auto i: nums){
            current = max(current, 0) + i;
            ans = max(ans, current);
        }
        return ans;
    }
};