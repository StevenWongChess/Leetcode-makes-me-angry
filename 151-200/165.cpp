class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int m = version1.size(), n = version2.size(), i = 0, j = 0;

        while (i < m || j < n)
        {
            int l = 0, r = 0;
            while (i < m && version1[i] != '.')
            {
                l *= 10;
                l += version1[i] - '0';
                ++i;
            }
            ++i;
            while (j < n && version2[j] != '.')
            {
                r *= 10;
                r += version2[j] - '0';
                ++j;
            }
            ++j;

            if (l > r)
                return 1;
            else if (l < r)
                return -1;
        }
        return 0;
    }
};