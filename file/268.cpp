class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int tmp = -1;
        for(int i = 0; i < n; i++){
            while(i != nums[i] && nums[i] != -1){
                if(nums[i] == n){
                    swap(tmp, nums[i]);
                    break;
                }
                else{
                    swap(nums[i], nums[nums[i]]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] == -1)
                return i;
        }
        return n;
    }
};