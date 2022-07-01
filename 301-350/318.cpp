class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int n = words.size(), ans = 0;
        vector<vector<bool> > v(n, vector<bool>(26, false));

        for (int i = 0; i < n; ++i)
        {
            for (auto j : words[i])
            {
                v[i][j - 'a'] = true;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                bool flag = true;
                for (int k = 0; k < 26; ++k)
                {
                    if (v[i][k] && v[j][k])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }

        return ans;
    }
};