class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> dict{{0, 1}};
        int prefix_sum = 0;
        int count = 0;

        for (auto i : nums)
        {
            prefix_sum += i;
            if (dict.find(prefix_sum - k) != dict.end())
            {
                count += dict[prefix_sum - k];
            }
            ++dict[prefix_sum];
        }
        return count;
    }
};