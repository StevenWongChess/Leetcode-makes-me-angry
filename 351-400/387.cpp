class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> dict;
        for (auto i : s)
        {
            dict[i]++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (dict[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int n = s.length();
        vector<int> dict(26, n);
        for (int i = n - 1; i >= 0; --i)
        {
            if (dict[s[i] - 'a'] == n)
            {
                dict[s[i] - 'a'] = i;
            }
            else if (dict[s[i] - 'a'] < n)
            {
                dict[s[i] - 'a'] = n + 1;
            }
        }
        int ans = *min_element(dict.begin(), dict.end());
        return ans < n ? ans : -1;
    }
};