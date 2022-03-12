class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int l = 0; int r = 0;
        for(auto i: nums){
            r += i;
        }
        for(int i = 0; i < n; i++){
            r -= nums[i];
            if(l == r)
                return i;
            l += nums[i];
        }
        return -1;
    }
};