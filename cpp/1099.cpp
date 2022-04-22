class Solution
{
public:
    int twoSumLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        sort(nums.begin(), nums.end());
        int ans = -1;

        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum < k)
            {
                ans = max(ans, sum);
                ++l;
            }
            else
            {
                --r;
            }
        }

        return ans;
    }
};