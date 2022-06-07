class Solution
{
public:
    int threeSumSmaller(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int new_target = target - nums[i];
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if (sum < new_target)
                {
                    ans += r - l;
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }

        return ans;
    }
};