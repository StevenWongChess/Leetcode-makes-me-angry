class Solution
{
public:
    int climbStairs(int n)
    {
        int first = 1;
        int second = 1;
        for (int i = 1; i < n; ++i)
        {
            auto tmp = second;
            second += first;
            first = tmp;
        }

        return second;
    }
};