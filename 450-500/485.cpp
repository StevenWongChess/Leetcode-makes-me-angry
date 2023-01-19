class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0, count = 0;
        for (auto i : nums)
        {
            if (i == 1)
            {
                ++count;
            }
            else
            {
                ans = max(ans, count);
                count = 0;
            }
        }
        return max(count, ans);
    }
};