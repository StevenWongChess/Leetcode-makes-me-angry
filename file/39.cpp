class Solution {
public:
    vector<vector<int>> ans;
    vector<int> list;
    void dfs(vector<int>& candidates, int ith, int target){
        int n = candidates.size();
        if(target == 0){
            ans.push_back(list);
            return;
        }
        else if(target < 0){
            return;
        }
        else{
            for(int i = ith; i < n; i++){
                list.push_back(candidates[i]);
                dfs(candidates, i, target - candidates[i]);
                list.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }
};