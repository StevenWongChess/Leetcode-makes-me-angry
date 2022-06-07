class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0;
        int r = x;
        while (l < r)
        {
            int mid = ((r - l) >> 1) + l + 1;
            if (mid >= INT_MAX / mid)
            {
                r = mid - 1;
                continue;
            }
            if (x == mid * mid)
                return mid;
            else if (x < mid * mid)
                r = mid - 1;
            else
                l = mid;
        }
        return l;
    }
};