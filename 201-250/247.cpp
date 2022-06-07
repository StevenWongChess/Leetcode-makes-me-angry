class Solution
{
public:
    unordered_map<char, char> map = {
        {'1', '1'},
        {'6', '9'},
        {'9', '6'},
        {'8', '8'},
        {'0', '0'}};
    vector<string> ans;

    void dfs(int n, int ith, string &s)
    {
        if (ith >= (n + 1) / 2)
        {
            ans.push_back(s);
            return;
        }

        for (auto [x, y] : map)
        {
            if (ith == 0 && ith != (n - 1 - ith) && x == '0' && ith == 0)
            {
                continue;
            }
            if (ith == n - 1 - ith && x != y)
            {
                continue;
            }
            s[ith] = x;
            s[n - 1 - ith] = y;
            dfs(n, ith + 1, s);
        }
    }

    vector<string> findStrobogrammatic(int n)
    {
        string s(n, ' ');
        dfs(n, 0, s);
        return ans;
    }
};