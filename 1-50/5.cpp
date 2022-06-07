class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans;
        int l = -1, r = -2, n = s.length();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; i - j >= 0 && i + j < n; ++j)
            {
                if (s[i + j] == s[i - j])
                {
                    if (1 + 2 * j > r - l + 1)
                    {
                        l = i - j;
                        r = i + j;
                    }
                }
                else
                    break;
            }

            for (int j = 0; i - j >= 0 && i + j + 1 < n; ++j)
            {
                if (s[i + j + 1] == s[i - j])
                {
                    if (2 + 2 * j > r - l + 1)
                    {
                        l = i - j;
                        r = i + j + 1;
                    }
                }
                else
                    break;
            }
        }

        return s.substr(l, r - l + 1);
    }
};