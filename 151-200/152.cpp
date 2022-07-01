class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int pmax = nums[0], nmin = nums[0], ans = nums[0];
        int n = nums.size();
        for (int j = 1; j < n; ++j)
        {
            int i = nums[j], x = pmax, y = nmin;
            pmax = max(i, max(i * x, i * y));
            nmin = min(i, min(i * x, i * y));
            ans = max(pmax, ans);
        }

        return ans;
    }
};