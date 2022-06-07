class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0;

        for (auto i : columnTitle)
        {
            int num = i - 'A';
            ++num;
            ans *= 26;
            ans += num;
        }

        return ans;
    }
};