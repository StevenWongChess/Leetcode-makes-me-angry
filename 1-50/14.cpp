class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        auto s1 = *max_element(strs.begin(), strs.end());
        auto s2 = *min_element(strs.begin(), strs.end());
        string ans = "";
        int len = s1.length();
        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                return s2.substr(0, i);
            }
        }
        return s1;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int m = strs.size();
        int minlen = INT_MAX;
        for (auto &i : strs)
        {
            int n = i.length();
            minlen = min(minlen, n);
        }
        string ans = "";
        for (int i = 0; i < minlen; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (strs[j][i] != strs[0][i])
                    return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};