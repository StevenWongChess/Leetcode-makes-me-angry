class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        unordered_map<char, int> dict;
        int n = s.size(), ans = 0, kinds = 0, l = 0;

        for (int i = 0; i < n; ++i)
        {
            ++dict[s[i]];
            if (dict[s[i]] == 1)
                ++kinds;
            while (l < i && kinds > 2)
            {
                --dict[s[l]];
                if (dict[s[l]] == 0)
                {
                    dict.erase(s[l]);
                    --kinds;
                }
                ++l;
            }
            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};
