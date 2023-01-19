class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        
        int diff = nums[0] - nums[1], count = 0, ans = 0;
        for(int i = 2; i < n; ++i){
            if(nums[i - 1] - nums[i] == diff){
                ++count;
                ans += count;
            }
            else{
                diff = nums[i - 1] - nums[i];
                count = 0;
            }
        }
        
        return ans;
    }
};