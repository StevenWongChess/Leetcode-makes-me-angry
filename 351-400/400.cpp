class Solution
{
public:
    int findNthDigit(int n)
    {
        int count = 9;
        int digits = 1;
        int ith = 0;

        while (n > (long)count * digits)
        {
            ith += count;
            n -= digits * count;
            count *= 10;
            ++digits;
        }

        // cout << ith << ", " << n << endl;

        int step = (n - 1) / digits;
        n -= step * digits;
        ith += step;

        ++ith;
        --n;

        for (int i = 0; i < digits - n - 1; ++i)
        {
            ith /= 10;
        }

        return ith % 10;
    }
};