class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0; int n = nums.size();
        int ans = n + 1;
        int start = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum >= target){
                ans = min(ans, i - start + 1);
                sum -= nums[start];
                start ++;
            }
        }
        return ans == n + 1 ? 0 : ans;
    }
};