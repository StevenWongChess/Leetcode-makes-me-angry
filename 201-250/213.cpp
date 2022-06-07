class Solution
{
public:
    int easy_rob(vector<int> &nums, int l, int r)
    {
        int rob = 0;
        int not_rob = 0;
        for (int i = l; i <= r; i++)
        {
            int tmp = rob;
            rob = not_rob + nums[i];
            not_rob = max(tmp, not_rob);
        }
        return max(rob, not_rob);
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return max(nums[0], nums[nums.size() - 1]);
        }
        return max(easy_rob(nums, 0, nums.size() - 2), easy_rob(nums, 1, nums.size() - 1));
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int f_rob = nums[0], f_nrob = nums[0], nf_rob = 0, nf_nrob = 0;
        for (int i = 2; i < n - 1; ++i)
        {
            int tmp = f_rob;
            f_rob = max(f_rob, f_nrob + nums[i]);
            f_nrob = max(f_nrob, tmp);
        }

        for (int i = 1; i < n; ++i)
        {
            int tmp = nf_rob;
            nf_rob = max(nf_rob, nf_nrob + nums[i]);
            nf_nrob = max(nf_nrob, tmp);
        }

        return max(max(f_rob, f_nrob), max(nf_rob, nf_nrob));
    }
};