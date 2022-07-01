/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int sum = 0, add = 4;
        char buf4[4];

        while (sum < n && add == 4)
        {
            add = read4(buf4);
            for (int i = 0; i < add; ++i)
            {
                if (n == sum)
                    return n;
                buf[sum] = buf4[i];
                ++sum;
            }
        }

        return sum;
    }
};