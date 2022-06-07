class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int round = min((n + 1) / 2, (m + 1) / 2);

        for (int i = 0; i < round; ++i)
        {
            for (int j = i; j < m - i; ++j)
            {
                ans.push_back(matrix[i][j]);
            }
            for (int j = i + 1; j < n - 1 - i; ++j)
            {
                ans.push_back(matrix[j][m - 1 - i]);
            }
            if (i < n - 1 - i)
            {
                for (int j = m - 1 - i; j >= i; --j)
                {
                    ans.push_back(matrix[n - 1 - i][j]);
                }
            }
            if (i < m - 1 - i)
            {
                for (int j = n - 2 - i; j >= i + 1; --j)
                {
                    ans.push_back(matrix[j][i]);
                }
            }
        }

        return ans;
    }
};