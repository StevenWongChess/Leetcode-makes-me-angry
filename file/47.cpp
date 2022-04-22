class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> nums, int ith){
        if(ith == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ith; i < nums.size(); i++){
            if(i != ith && nums[i] == nums[ith])
                continue;
            swap(nums[i], nums[ith]);
            dfs(nums, ith + 1);
            // swap(nums[i], nums[ith]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};