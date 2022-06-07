class Solution
{
public:
    int numWays(int n, int k)
    {
        if (n == 1)
            return k;
        int good = k * (k - 1), bad = k;
        for (int i = 3; i <= n; ++i)
        {
            int new_good = good * (k - 1) + bad * (k - 1);
            int new_bad = good;
            good = new_good, bad = new_bad;
        }

        return good + bad;
    }
};