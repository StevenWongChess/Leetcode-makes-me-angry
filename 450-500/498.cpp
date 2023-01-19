class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int> > &mat)
    {
        int m = mat.size(), n = mat[0].size();
        int mult = m * n;
        int small = min(m, n);

        vector<int> ans;
        int i = 0, j = 0;
        while (ans.size() < mult)
        {
            while (i >= 0 && j < n)
            {
                ans.push_back(mat[i][j]);
                --i;
                ++j;
            }
            ++i;
            if (j == n)
            {
                ++i;
                --j;
            }
            while (i < m && j >= 0)
            {
                ans.push_back(mat[i][j]);
                ++i;
                --j;
            }
            ++j;
            if (i == m)
            {
                --i;
                ++j;
            }
        }

        return ans;
    }
};