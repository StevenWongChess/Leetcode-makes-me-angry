class Solution
{
public:
    vector<vector<int> > ans;
    vector<int> line;
    int sum = 0;

    void dfs(int k, int n, int ith)
    {
        if (ith >= k)
        {
            if (sum == n)
            {
                ans.push_back(line);
            }
            return;
        }

        int start = line.empty() ? 1 : *line.rbegin() + 1;
        for (int i = start; i < 10; ++i)
        {
            sum += i;
            line.push_back(i);
            dfs(k, n, ith + 1);
            sum -= i;
            line.pop_back();
        }
    }

    vector<vector<int> > combinationSum3(int k, int n)
    {
        dfs(k, n, 0);
        return ans;
    }
};