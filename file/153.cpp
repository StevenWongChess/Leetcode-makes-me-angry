class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        // if(r == 0)
        //     return nums[0];
        while(l < r){
            int mid = (r - l) / 2 + l;
            if(nums[l] < nums[r])
                return nums[l];
            if(nums[mid] < nums[l])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};