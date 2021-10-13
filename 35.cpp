class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left < right){
            mid = ((right - left) >> 1) + left;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }   
        return nums[left] < target ? left + 1 : left;
    }
};