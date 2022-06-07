class Solution
{
public:
    vector<vector<int> > ans;
    vector<int> line;
    void dfs(int n)
    {
        for (int i = line.empty() ? 2 : line.back(); i <= n / i; ++i)
        {
            if (n % i == 0)
            {
                line.push_back(i);
                line.push_back(n / i);
                ans.push_back(line);
                line.pop_back();
                dfs(n / i);
                line.pop_back();
            }
        }
    }

    vector<vector<int> > getFactors(int n)
    {
        dfs(n);
        return ans;
    }
};