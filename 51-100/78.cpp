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
        dfs(nums, n, k + 1);
        line.push_back(nums[k]);
        dfs(nums, n, k + 1);
        line.pop_back();
    }

    vector<vector<int> > subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dfs(nums, n, 0);

        return ans;
    }
};