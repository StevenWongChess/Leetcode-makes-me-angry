class Solution
{
public:
    vector<vector<int> > ans;
    vector<int> line;
    unordered_map<int, int> freq;

    void dfs(vector<int> &nums, int ith)
    {
        int n = nums.size();
        if (ith == n)
        {
            ans.push_back(line);
            return;
        }

        for (auto &[x, y] : freq)
        {
            if (y <= 0)
                continue;

            line.push_back(x);
            --y;
            dfs(nums, ith + 1);
            ++y;
            line.pop_back();
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (auto i : nums)
        {
            ++freq[i];
        }
        dfs(nums, 0);
        return ans;
    }
};

class Solution
{
public:
    vector<vector<int> > ans;
    void dfs(vector<int> &nums, int n, int k)
    {
        if (k >= n)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = k; i < n; ++i)
        {
            swap(nums[k], nums[i]);
            dfs(nums, n, k + 1);
            swap(nums[k], nums[i]);
        }
    }

    vector<vector<int> > permute(vector<int> &nums)
    {
        int n = nums.size();
        dfs(nums, n, 0);

        return ans;
    }
};