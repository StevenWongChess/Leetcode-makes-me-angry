class Solution
{
public:
    unordered_map<string, bool> dict;

    bool canWin(string s)
    {
        if (dict.count(s))
            return dict[s];
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == '+' && s[i] == '+')
            {
                s[i - 1] = s[i] = '-';
                bool flag = dict.count(s) ? dict[s] : canWin(s);
                if (!flag)
                {
                    s[i - 1] = s[i] = '+';
                    dict[s] = true;
                    s[i - 1] = s[i] = '-';
                    return true;
                }
                s[i - 1] = s[i] = '+';
            }
        }
        dict[s] = false;
        return false;
    }
};