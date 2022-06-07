class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> dict1;
        unordered_map<char, char> dict2;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            if (dict1.count(s[i]))
            {
                if (dict1[s[i]] != t[i])
                    return false;
            }
            else
            {
                dict1[s[i]] = t[i];
            }
            if (dict2.count(t[i]))
            {
                if (dict2[t[i]] != s[i])
                    return false;
            }
            else
            {
                dict2[t[i]] = s[i];
            }
        }
        return true;
    }
};