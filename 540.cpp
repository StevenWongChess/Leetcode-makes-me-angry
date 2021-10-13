class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(mid < nums.size() - 1 && nums[mid] == nums[mid + 1]){
                if((mid - l) % 2 == 0)
                    l = mid + 2;
                else
                    r = mid - 1;
            }
            else if(mid > 0 && nums[mid] == nums[mid - 1]){
                if((mid - l) % 2 == 0)
                    r = mid - 2;
                else
                    l = mid + 1;
            }
            else{
                return nums[mid];
            }
        }
        return nums[l];
    }
};