class Solution
{
public:
    int numOfPairs(vector<string> &nums, string target)
    {
        unordered_map<string, int> dict;
        for (auto i : nums)
        {
            ++dict[i];
        }
        int ans = 0;

        for (auto i : nums)
        {
            auto first = target.substr(0, i.length());
            if (i == first)
            {
                auto second = target.substr(i.length(), target.length() - i.length());
                if (dict.count(second))
                {
                    ans += dict[second];
                    if (first == second)
                        --ans;
                }
            }
        }
        return ans;
    }
};