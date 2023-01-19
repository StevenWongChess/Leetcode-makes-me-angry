class Solution {
public:
    vector<vector<int>> ans;
    vector<int> line;
    int n = 0;
    
    void dfs(int ith, int last, vector<int>& nums){
        if(ith == n){
            if(line.size() > 1){
                ans.push_back(line);
            }
            return;
        }
        if(nums[ith] >= last){
            line.push_back(nums[ith]);
            dfs(ith + 1, nums[ith], nums);
            line.pop_back();
        }
        if(nums[ith] != last){
            dfs(ith + 1, last, nums);
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        dfs(0, -101, nums);
        return ans;
    }
};