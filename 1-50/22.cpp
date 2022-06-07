class Solution
{
public:
    vector<string> ans;
    string line;

    void dfs(int n, int l, int r)
    {
        if (l + r == 2 * n)
        {
            ans.push_back(line);
            return;
        }
        if (l < n)
        {
            line.push_back('(');
            dfs(n, l + 1, r);
            line.pop_back();
        }
        if (r < l)
        {
            line.push_back(')');
            dfs(n, l, r + 1);
            line.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        dfs(n, 0, 0);
        return ans;
    }
};