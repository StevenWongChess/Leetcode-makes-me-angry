class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> dict;

        for (auto i : nums)
        {
            if (dict.count(i))
                return true;
            ++dict[i];
        }

        return false;
    }
};