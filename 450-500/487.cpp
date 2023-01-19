class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int a = 0, b = 0, ans = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] == 1){
                ++b;
            }
            else{
                a = b + 1;
                b = 0;
            }
            ans = max(ans, a + b);
        }
        return ans;
    }
};