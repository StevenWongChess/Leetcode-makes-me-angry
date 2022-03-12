class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int it = i;
            while(nums[it] - 1 != it && nums[it] != nums[nums[it] - 1]){
                swap(nums[it], nums[nums[it] - 1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                ans.push_back(i + 1);
        }
        return ans;
    }
};