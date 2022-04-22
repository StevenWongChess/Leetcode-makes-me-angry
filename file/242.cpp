class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> dp(26, 0);
        for (auto i : s)
        {
            ++dp[i - 'a'];
        }
        for (auto i : t)
        {
            --dp[i - 'a'];
        }
        for (auto i : dp)
        {
            if (i != 0)
                return false;
        }
        return true;
    }
};