class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.length();
        int n = num2.length();
        if (num1[0] == '0' || num2[0] == '0')
            return "0";

        vector<int> dp(m + n);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int carry = 0;
        for (int i = m + n - 1; i >= 0; --i)
        {
            int sum = carry + dp[i];
            carry = sum / 10;
            dp[i] = sum % 10;
        }

        string ans;
        if (dp[0] != 0)
            ans.push_back(dp[0] + '0');
        for (int i = 1; i < m + n; ++i)
        {
            ans.push_back(dp[i] + '0');
        }

        return ans;
    }
};