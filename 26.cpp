class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        int prev = nums[0];
        int j = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == prev)
                continue;
            else{
                prev = nums[i];
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j;
    }
};