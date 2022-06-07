class Solution
{
public:
    vector<vector<int> > ans;
    vector<int> set;
    void dfs(vector<int> &candidates, int n, int k, int target)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            ans.push_back(set);
            return;
        }
        for (int i = k; i < n; ++i)
        {
            set.push_back(candidates[i]);
            dfs(candidates, n, i, target - candidates[i]);
            set.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        dfs(candidates, n, 0, target);
        return ans;
    }
};