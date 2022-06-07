class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > ans(n, vector<int>(n));
        int count = 0;
        for (int i = 0; i < (n + 1) / 2; ++i)
        {
            for (int j = i; j <= n - 1 - i; ++j)
            {
                ans[i][j] = ++count;
            }
            for (int j = i + 1; j < n - 1 - i; ++j)
            {
                ans[j][n - 1 - i] = ++count;
            }
            if (i < n - 1 - i)
            {
                for (int j = n - 1 - i; j >= i; --j)
                {
                    ans[n - 1 - i][j] = ++count;
                }
                for (int j = n - 2 - i; j > i; --j)
                {
                    ans[j][i] = ++count;
                }
            }
        }

        return ans;
    }
};