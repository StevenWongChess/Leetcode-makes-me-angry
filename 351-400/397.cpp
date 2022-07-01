class Solution
{
public:
    unordered_map<int, int> dict;

    int integerReplacement(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        if (dict.count(n))
            return dict[n];

        if (n & 1)
        {
            dict[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
            return dict[n];
        }
        else
        {
            dict[n] = 1 + integerReplacement(n / 2);
            return dict[n];
        }
    }
};