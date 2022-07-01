class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        int ans = 0;

        for (int i = 1; i <= 26; ++i)
        {
            unordered_map<char, int> dict;
            int kinds = 0, satisfy = 0, l = 0, r = 0;

            while (r < n)
            {
                ++dict[s[r]];
                if (dict[s[r]] == 1)
                {
                    ++kinds;
                }
                if (dict[s[r]] == k)
                {
                    ++satisfy;
                }

                while (kinds > i)
                {
                    --dict[s[l]];
                    if (dict[s[l]] == k - 1)
                    {
                        --satisfy;
                    }
                    if (dict[s[l]] == 0)
                    {
                        --kinds;
                    }
                    ++l;
                }

                if (satisfy == i)
                {
                    ans = max(ans, r - l + 1);
                }

                ++r;
            }
        }

        return ans;
    }
};