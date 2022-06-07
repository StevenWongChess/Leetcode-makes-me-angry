class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            if (s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
            if (s.size() > k)
                s.erase(nums[i - k]);
        }
        return false;
    }
};

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> dict;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (dict.count(nums[i]) && i - dict[nums[i]] <= k)
                return true;
            dict[nums[i]] = i;
        }

        return false;
    }
};