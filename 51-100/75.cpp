class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int i = 0;

        while (i <= r)
        {
            while (i <= r && nums[i] == 2)
            {
                swap(nums[i], nums[r]);
                --r;
            }
            if (nums[i] == 0)
            {
                swap(nums[i], nums[l]);
                ++l;
            }
            ++i;
        }
    }
};