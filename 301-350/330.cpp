class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long x = 1;
        int m = nums.size(), it = 0, ans = 0;

        while(x <= n){
            if(it < m && nums[it] <= x){
                x += nums[it];
                ++it;
            }
            else{
                x <<= 1;
                ++ans;
            }
        }

        return ans;
    }
};