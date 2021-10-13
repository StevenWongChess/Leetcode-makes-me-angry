class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int j = i;
            while(nums[j] > 0 && nums[j] < n + 1 && nums[j] != nums[nums[j] - 1]){
                swap(nums[j], nums[nums[j] - 1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};