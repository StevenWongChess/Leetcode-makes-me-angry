class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        for(auto i: nums){
            ans += abs(i - nums[n / 2]);
        }
        return ans;
    }
};