class Solution
{
public:
    vector<vector<int> > multiply(vector<vector<int> > &mat1, vector<vector<int> > &mat2)
    {
        int a = mat1.size(), b = mat1[0].size(), c = mat2[0].size();
        vector<vector<int> > ans(a, vector<int>(c, 0));

        vector<vector<pair<int, int> > > m1(a);
        for (int i = 0; i < a; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                if (mat1[i][j] != 0)
                {
                    m1[i].push_back({j, mat1[i][j]});
                }
            }
        }

        vector<vector<pair<int, int> > > m2(c);
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (mat2[i][j] != 0)
                {
                    m2[j].push_back({i, mat2[i][j]});
                }
            }
        }

        for (int i = 0; i < a; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                int l = 0, r = 0, size1 = m1[i].size(), size2 = m2[j].size();
                while (l < size1 && r < size2)
                {
                    if (m1[i][l].first == m2[j][r].first)
                    {
                        ans[i][j] += m1[i][l].second * m2[j][r].second;
                        ++l;
                        ++r;
                    }
                    else if (m1[i][l].first < m2[j][r].first)
                    {
                        ++l;
                    }
                    else
                    {
                        ++r;
                    }
                }
            }
        }
        return ans;
    }
};