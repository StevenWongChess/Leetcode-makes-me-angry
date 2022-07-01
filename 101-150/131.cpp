class Solution
{
public:
    vector<vector<string> > ans;
    vector<string> line;
    void dfs(string &s, int ith, vector<vector<bool> > &dp)
    {
        int n = s.size();
        if (ith == n)
        {
            ans.push_back(line);
            return;
        }

        for (int i = 0; ith + i < n; ++i)
        {
            if (dp[ith][ith + i])
            {
                line.push_back(s.substr(ith, i + 1));
                dfs(s, ith + i + 1, dp);
                line.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s)
    {
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            for (int j = 1; i + j < n && i - j >= 0; ++j)
            {
                auto tmp = dp[i - j + 1][i + j - 1] && s[i - j] == s[i + j];
                if (tmp)
                    dp[i - j][i + j] = true;
                else
                    break;
            }

            if (i + 1 < n)
            {
                dp[i][i + 1] = (s[i] == s[i + 1]);
            }
            for (int j = 1; i + 1 + j < n && i - j >= 0; ++j)
            {
                auto tmp = dp[i - j + 1][i + j] && s[i - j] == s[i + j + 1];
                if (tmp)
                    dp[i - j][i + j + 1] = true;
                else
                    break;
            }
        }
        dfs(s, 0, dp);
        return ans;
    }
};