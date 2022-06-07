class Solution
{
public:
    vector<vector<int> > ans;
    vector<int> line;
    void dfs(int n, int k, int ith)
    {
        if (k == 0)
        {
            ans.push_back(line);
            return;
        }
        if (ith > n)
        {
            return;
        }

        for (int i = ith; i <= n; i++)
        {
            line.push_back(i);
            dfs(n, k - 1, i + 1);
            line.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k)
    {
        dfs(n, k, 1);
        return ans;
    }
};