class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int l = 0, n = s.length();
        unordered_map<int, int> dict;
        for (int i = 0; i < n; ++i)
        {
            ++dict[s[i]];
            while (dict[s[i]] > 1)
            {
                --dict[s[l]];
                ++l;
            }
            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};