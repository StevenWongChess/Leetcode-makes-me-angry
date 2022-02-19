class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int first = INT_MIN;
        int second = INT_MIN;
        for(int i = 0; i < n; i++){
            if(l > 1 && nums[i] == nums[l - 1] && nums[i] == nums[l - 2]){
                continue;
            }
            else{
                nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
};