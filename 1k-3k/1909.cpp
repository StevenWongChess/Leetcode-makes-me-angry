class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        bool flag = false;
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i - 1]){
                if(flag)
                    return false;
                flag = true;
                if(i != 1 && i != n - 1 &&  nums[i] <= nums[i - 2] && nums[i - 1] >= nums[i + 1])
                    return false;
            }
        }
        return true;
    }
};