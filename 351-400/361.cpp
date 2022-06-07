class Solution
{
public:
    int maxKilledEnemies(vector<vector<char> > &grid)
    {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> up(n);
        vector<int> down(n);

        for (int j = 0; j < n; ++j)
        {
            int it = 0;
            int count = 0;
            while (it < m && grid[it][j] != 'W')
            {
                if (grid[it][j] == 'E')
                    ++count;
                ++it;
            }
            down[j] += count;
        }

        for (int i = 0; i < m; ++i)
        {
            // init
            int l = 0;
            int r = 0;
            int it = 0;
            while (it < n && grid[i][it] != 'W')
            {
                if (grid[i][it] == 'E')
                    ++r;
                ++it;
            }

            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 'W')
                {
                    l = r = 0;
                    int it = j + 1;
                    int count = 0;
                    while (it < n && grid[i][it] != 'W')
                    {
                        if (grid[i][it] == 'E')
                            ++r;
                        ++it;
                    }
                    it = i + 1;
                    up[j] = 0;
                    while (it < m && grid[it][j] != 'W')
                    {
                        if (grid[it][j] == 'E')
                            ++count;
                        ++it;
                    }
                    down[j] = count;
                }
                else if (grid[i][j] == 'E')
                {
                    ++l;
                    --r;
                    ++up[j];
                    --down[j];
                }
                else
                {
                    ans = max(ans, up[j] + down[j] + l + r);
                }
            }
        }

        return ans;
    }
};