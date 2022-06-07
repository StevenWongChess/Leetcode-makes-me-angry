class Solution
{
public:
    int count_digits(int n)
    {
        int count = 0;
        while (n)
        {
            n /= 10;
            ++count;
        }
        return count;
    }

    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (auto i : nums)
        {
            if (count_digits(i) % 2 == 0)
                ++ans;
        }
        return ans;
    }
};