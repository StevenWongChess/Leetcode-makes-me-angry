class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[0] <= nums[mid]){
                if(nums[mid] > target && target >= nums[0])
                    r = mid - 1;
                else    
                    l = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[n - 1])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};