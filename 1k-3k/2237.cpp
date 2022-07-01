class Solution
{
public:
    int meetRequirement(int n, vector<vector<int> > &lights, vector<int> &requirement)
    {
        vector<int> dp(n);
        for (auto i : lights)
        {
            int start = max(i[0] - i[1], 0), end = i[0] + i[1] + 1;
            ++dp[start];
            if (end < n)
            {
                --dp[end];
            }
        }

        int ans = 0, brightness = 0;
        for (int i = 0; i < n; ++i)
        {
            brightness += dp[i];
            if (brightness >= requirement[i])
                ++ans;
        }

        return ans;
    }
};