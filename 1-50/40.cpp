class Solution
{
public:
    vector<pair<int, int> > freq;
    vector<vector<int> > ans;
    vector<int> set;
    void dfs(int n, int k, int target)
    {
        if (target == 0)
        {
            ans.push_back(set);
            return;
        }
        if (k >= n || target < 0)
            return;

        int times = min(freq[k].second, target / freq[k].first);
        for (int i = 0; i <= times; ++i)
        {
            if (i > 0)
                set.push_back(freq[k].first);
            dfs(n, k + 1, target - i * freq[k].first);
        }
        for (int i = 1; i <= times; ++i)
        {
            set.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        for (auto i : candidates)
        {
            if (freq.empty() || freq.back().first != i)
                freq.push_back({i, 1});
            else
                ++freq.back().second;
        }
        int n = freq.size();
        dfs(n, 0, target);

        return ans;
    }
};