class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void dfs(vector<int>& candidates, int range, int target, vector<int>& v){
        if(target < 0)
            return;
        else if(target == 0)
            ans.push_back(v);
        else{
            for(int i = 0; i <= range; i++){
                v.push_back(candidates[i]);
                dfs(candidates, i, target - candidates[i], v);
                v.pop_back();
            }
        }
    }   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        dfs(candidates, n - 1, target, v);
        return ans;
    }
};