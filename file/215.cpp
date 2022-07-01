class Solution
{
public:
    int select(vector<int> &nums, int l, int r, int k)
    {
        int index = rand() % (r - l + 1) + l, it = l;
        swap(nums[index], nums[r]);
        for (int i = l; i < r; ++i)
        {
            if (nums[i] <= nums[r])
            {
                swap(nums[it], nums[i]);
                ++it;
            }
        }
        swap(nums[r], nums[it]);
        if (it == k)
        {
            return nums[k];
        }
        else if (it > k)
        {
            return select(nums, l, it - 1, k);
        }
        else
        {
            return select(nums, it + 1, r, k);
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater{});
        // return nums[k - 1];
        srand(0);
        int n = nums.size();
        return select(nums, 0, n - 1, n - k);
    }
};