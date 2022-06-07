class Solution
{
public:
    vector<string> dict = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};
    vector<string> ans;
    string line;
    void dfs(string &digits, int n, int k)
    {
        if (k >= n)
        {
            ans.push_back(line);
            return;
        }

        for (auto i : dict[digits[k] - '2'])
        {
            line.push_back(i);
            dfs(digits, n, k + 1);
            line.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        int n = digits.length();
        if (n == 0)
            return {};

        dfs(digits, n, 0);
        return ans;
    }
};