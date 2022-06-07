class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            while (nums[i] != i && nums[i] < n)
            {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};