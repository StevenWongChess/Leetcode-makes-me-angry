class Solution {
public:
    int find_pos(vector<int>& nums, int target, int flag){
        int left = 0;
        int right = nums.size() - 1;
        if(right == -1)
            return -1;
        while(left < right){
            int mid = ((right - left + flag) >> 1) + left;
            if(nums[mid] > target)
                right = mid - flag;
            else if(nums[mid] == target){
                if(flag == 0)
                    right = mid;
                else
                    left = mid;
            }
            else
                left = mid + 1 - flag;
        }
        return nums[left] == target ? left : -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {find_pos(nums, target, 0), find_pos(nums, target, 1)};
    }
};