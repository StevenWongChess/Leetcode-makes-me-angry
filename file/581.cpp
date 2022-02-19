class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = n; int right = -1;
        int max_ = INT_MIN;
        int min_ = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] >= max_)
                max_ = nums[i];
            else
                right = i;
        }
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] <= min_)
                min_ = nums[i];
            else
                left = i;
        }
        if(right == -1)
            return 0;
        return right - left + 1;
    }
};