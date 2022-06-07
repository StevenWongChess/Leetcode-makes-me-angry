class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int min_value = INT_MAX;
        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < min_value)
                {
                    min_value = abs(target - sum);
                    ans = sum;
                }
                if (sum == target)
                {
                    return sum;
                }
                else if (sum < target)
                {
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