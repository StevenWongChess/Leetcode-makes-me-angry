class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> dict;
        int count = 0;

        for (auto i : nums)
        {
            if (dict.find(i + k) != dict.end())
                count += dict[i + k];
            if (dict.find(i - k) != dict.end())
                count += dict[i - k];
            dict[i]++;
        }
        return count;
    }
};