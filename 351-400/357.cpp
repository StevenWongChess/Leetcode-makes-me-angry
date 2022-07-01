class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        int ans = 10, non_zero = 9;

        for (int i = 1; i < n; ++i)
        {
            non_zero *= (10 - i);
            ans += non_zero;
        }

        return ans;
    }
};