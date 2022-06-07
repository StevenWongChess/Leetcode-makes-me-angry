class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0)
            return 0;
        if (n < 0)
            x = 1 / x;
        double pow = x;
        double ans = 1;
        while (n)
        {
            if (n & 1)
                ans *= pow;
            pow *= pow;
            n /= 2;
        }
        return ans;
    }
};