class Solution
{
public:
    vector<string> ans;
    void dfs(int n, int ith, vector<int> &dict, string &line)
    {
        if (ith >= n - 1 - ith)
        {
            if (ith == n - 1 - ith)
            {
                for (int i = 0; i < 26; ++i)
                {
                    if (dict[i] == 1)
                    {
                        line[ith] = (i + 'a');
                    }
                }
            }
            ans.push_back(line);
            return;
        }

        for (int i = 0; i < 26; ++i)
        {
            if (dict[i] > 1)
            {
                line[ith] = line[n - 1 - ith] = (i + 'a');
                dict[i] -= 2;
                dfs(n, ith + 1, dict, line);
                dict[i] += 2;
            }
        }
    }

    vector<string> generatePalindromes(string s)
    {
        int n = s.length();
        vector<int> dict(26, 0);
        for (auto i : s)
        {
            ++dict[i - 'a'];
        }
        int count = 0;
        for (auto i : dict)
        {
            if (i % 2 == 1)
                ++count;
        }
        if (count > 1)
            return {};

        string line(n, ' ');
        dfs(n, 0, dict, line);
        return ans;
    }
};