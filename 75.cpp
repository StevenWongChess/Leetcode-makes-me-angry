class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[l]);
                l++;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] == 2){
                swap(nums[i], nums[r]);
                r--;
            }
        }
    }
};