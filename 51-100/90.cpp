class Solution
{
public:
    vector<vector<int> > ans;
    vector<int> line;
    void dfs(vector<int> &nums, int ith, bool flag)
    {
        if (ith == nums.size())
        {
            ans.push_back(line);
            return;
        }
        line.push_back(nums[ith]);
        dfs(nums, ith + 1, true);
        line.pop_back();
        if (flag && ith > 0 && nums[ith] == nums[ith - 1])
        {
            return;
        }
        dfs(nums, ith + 1, false);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, true);
        return ans;
    }
};

class Solution
{
public:
    vector<vector<int> > ans;
    vector<int> line;

    void dfs(vector<int> &nums, int n, int k)
    {
        if (k >= n)
        {
            ans.push_back(line);
            return;
        }
        int it = k + 1;
        while (it < n && nums[it] == nums[k])
        {
            ++it;
        }
        dfs(nums, n, it);
        line.push_back(nums[k]);
        dfs(nums, n, k + 1);
        line.pop_back();
    }

    vector<vector<int> > subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, nums.size(), 0);
        return ans;
    }
};