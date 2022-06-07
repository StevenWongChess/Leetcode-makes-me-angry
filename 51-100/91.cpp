class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        if (n == 0 || s[0] == '0')
            return 0;

        int a = 1, b = 1;

        for (int i = 1; i < n; ++i)
        {
            int num = 10 * (s[i - 1] - '0') + (s[i] - '0');
            if (num % 10 == 0)
            {
                if (num == 0 || num > 20)
                    return 0;
                else
                {
                    swap(a, b);
                }
            }
            else
            {
                if (num > 26 || num < 10)
                {
                    a = b;
                }
                else
                {
                    swap(a, b);
                    b += a;
                }
            }
        }

        return b;
    }
};