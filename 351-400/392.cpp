class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int m = s.length(), n = t.length();
        int l = 0, r = 0;

        while (l < m && r < n)
        {
            if (s[l] == t[r])
            {
                ++l;
                ++r;
            }
            else
            {
                ++r;
            }
        }

        return l == m;
    }
};

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int m = s.length(), n = t.length();
        vector<vector<int> > dp(n + 1, vector<int>(26, 0));

        for (int i = 0; i < 26; ++i)
        {
            dp[n][i] = n;
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j < 26; ++j)
            {
                dp[i][j] = (t[i] == 'a' + j) ? i : dp[i + 1][j];
            }
        }

        int it = 0;
        for (int i = 0; i < m; ++i)
        {
            if (dp[it][s[i] - 'a'] == n)
            {
                return false;
            }
            it = dp[it][s[i] - 'a'] + 1;
        }

        return true;
    }
};