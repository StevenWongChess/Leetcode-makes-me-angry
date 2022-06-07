class Solution
{
public:
    int lastRemaining(int n)
    {
        bool to_right = true;
        int ans = 1, step = 1;

        while (n > 1)
        {
            if (to_right)
            {
                ans += step;
            }
            else
            {
                ans += (n % 2 == 0) ? 0 : step;
            }

            step <<= 1;
            n >>= 1;
            to_right = !to_right;
        }

        return ans;
    }
};