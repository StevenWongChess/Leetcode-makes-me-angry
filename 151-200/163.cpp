class Solution
{
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        vector<string> ans;

        if (n == 0 || upper + 1 != nums[n - 1])
            nums.push_back(upper + 1);
        if (n == 0 || lower - 1 != nums[0])
            nums.insert(nums.begin(), lower - 1);

        n = nums.size();
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i] + 1 == nums[i + 1])
            {
                continue;
            }
            else
            {
                int start = nums[i] + 1, end = nums[i + 1] - 1;
                ans.push_back(start == end ? to_string(start) : to_string(start) + "->" + to_string(end));
            }
        }

        return ans;
    }
};