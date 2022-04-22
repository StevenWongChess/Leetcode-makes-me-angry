class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int ith){
        if(ith == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ith; i < nums.size(); i++){
            swap(nums[ith], nums[i]);
            dfs(nums, ith + 1);
            swap(nums[ith], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};