class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        // return __builtin_popcount(x ^ y);
        int it = x ^ y, cnt = 0;
        while (it)
        {
            it = it & (it - 1);
            ++cnt;
        }
        return cnt;
    }
};