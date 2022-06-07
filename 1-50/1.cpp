class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> dict;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            dict[nums[i]] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            if (dict.find(target - nums[i]) != dict.end() && dict[target - nums[i]] != i)
            {
                return {i, dict[target - nums[i]]};
            }
        }
        return {};
    }
};