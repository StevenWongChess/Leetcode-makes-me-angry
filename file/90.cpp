class Solution {
public:
    vector<vector<int>> ans;
    vector<int> line;
    void dfs(vector<int>& nums, int ith, bool flag){
        if(ith == nums.size()){
            ans.push_back(line);
            return;
        }
        line.push_back(nums[ith]);
        dfs(nums, ith + 1, true);
        line.pop_back();
        if(flag && ith > 0 && nums[ith] == nums[ith - 1]){
            return;
        }
        dfs(nums, ith + 1, false);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, true);
        return ans;
    }
};