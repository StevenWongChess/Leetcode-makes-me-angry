class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int sum = 0;
        for (auto i : nums)
        {
            sum ^= i;
        }
        int lsb = (sum == INT_MIN) ? sum : (sum & (-sum));
        int a = 0;
        int b = 0;
        for (auto i : nums)
        {
            if (i & lsb)
            {
                a ^= i;
            }
            else
            {
                b ^= i;
            }
        }
        return {a, b};
    }
};