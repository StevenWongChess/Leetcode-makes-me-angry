class Solution
{
public:
    struct Segment
    {
        int lSum, rSum, best, total;
    };

    Segment get(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return {nums[l], nums[l], nums[l], nums[l]};
        auto l_seg = get(nums, l, (l + r) / 2);
        auto r_seg = get(nums, (l + r) / 2 + 1, r);

        return {max(l_seg.lSum, l_seg.total + r_seg.lSum), max(r_seg.rSum, l_seg.rSum + r_seg.total), max(max(l_seg.best, r_seg.best), l_seg.rSum + r_seg.lSum), l_seg.total + r_seg.total};
    }

    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        return get(nums, 0, n - 1).best;

        // int ans = INT_MIN;
        // int prefix = 0;
        // for(auto i: nums){
        //     prefix += i;
        //     ans = max(ans, prefix);
        //     prefix = max(prefix, 0);
        // }
        // return ans;
    }
};