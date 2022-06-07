class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        for (int i = 0; i < n; ++i)
        {
            if (l == 0 || nums[i] != nums[l - 1])
            {
                swap(nums[i], nums[l]);
                ++l;
            }
        }
        return l;
    }
};