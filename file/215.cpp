class Solution
{
public:
    int select(vector<int> &nums, int l, int r, int k)
    {
        int random_num = rand() % (r - l + 1) + l;
        swap(nums[random_num], nums[r]);
        int pivot = l;
        for (int i = l; i < r; i++)
        {
            if (nums[i] <= nums[r])
            {
                swap(nums[i], nums[pivot]);
                pivot++;
            }
        }
        swap(nums[pivot], nums[r]);
        if (pivot == k)
            return nums[pivot];
        else if (pivot > k)
            return select(nums, l, pivot - 1, k);
        else
            return select(nums, pivot + 1, r, k);
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        // srand(0);
        int n = nums.size();
        // return select(nums, 0, n - 1, n - k);
        nth_element(nums.begin(), nums.begin() + n - k, nums.end());
        return nums[n - k];
    }
};