class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string ans;
        int n = s.length();
        int cycle = (2 * numRows - 2);
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < (n - 1) / cycle + 1; ++j)
            {
                if (j * cycle + i < n)
                {
                    ans.push_back(s[j * cycle + i]);
                }
                if (i != 0 && i != numRows - 1 && (j + 1) * cycle - i < n)
                {
                    ans.push_back(s[(j + 1) * cycle - i]);
                }
            }
        }
        return ans;
    }
};