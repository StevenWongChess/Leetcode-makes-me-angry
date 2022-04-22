class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(count == 0 || nums[i] != nums[count - 1]){
                swap(nums[i], nums[count]);
                count++;
            }
        }
        return count;
    }
};