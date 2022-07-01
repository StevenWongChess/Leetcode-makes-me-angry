class Solution
{
public:
    int lastRemaining(int n)
    {
        bool to_right = true;
        int ans = 1, step = 1;

        while (n > 1)
        {
            ans += (to_right || (n & 1)) ? step : 0;

            step <<= 1;
            n >>= 1;
            to_right = !to_right;
        }

        return ans;
    }
};