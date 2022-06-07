class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (l < 2 || nums[l - 1] != nums[i] || nums[l - 2] != nums[i])
            {
                swap(nums[i], nums[l]);
                ++l;
            }
        }

        return l;
    }
};