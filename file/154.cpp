class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            if(nums[l] == nums[r])
                l++;
            else if(nums[l] < nums[r])
                return nums[l];
            else{
                int mid = (r - l) / 2 + l;
               if(nums[mid] >= nums[l]){
                   l = mid + 1;
               }
               else{
                   r = mid;
               }
            }
        }
        return nums[l];
    }
};