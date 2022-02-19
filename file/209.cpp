class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int l = 0; int r = 0;
        int sum = 0;
        while(r < nums.size()){
            sum += nums[r];
            r++;
            while(sum >= target){
                ans = min(ans, r - l);
                sum -= nums[l];
                l++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};