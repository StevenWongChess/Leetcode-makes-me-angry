class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> dict;
        vector<int> ans;
        for (auto i : p)
        {
            ++dict[i];
        }
        int n = s.length(), m = p.length(), count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dict.count(s[i]))
            {
                --dict[s[i]];
                if (dict[s[i]] >= 0)
                    ++count;
            }
            if (i >= m)
            {
                if (dict.count(s[i - m]))
                {
                    ++dict[s[i - m]];
                    if (dict[s[i - m]] > 0)
                    {
                        --count;
                    }
                }
            }
            if (count == m)
            {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};