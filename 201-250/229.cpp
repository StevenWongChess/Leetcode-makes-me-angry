class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> candidates({INT_MIN, INT_MIN});
        vector<int> counts(2, 0);

        for (auto i : nums)
        {
            if (i == candidates[0] && counts[0] > 0)
            {
                ++counts[0];
            }
            else if (i == candidates[1] && counts[1] > 0)
            {
                ++counts[1];
            }
            else if (counts[0] <= 0)
            {
                candidates[0] = i;
                ++counts[0];
            }
            else if (counts[1] <= 0)
            {
                candidates[1] = i;
                ++counts[1];
            }
            else
            {
                --counts[0];
                --counts[1];
            }
        }

        vector<int> ans;
        for (auto i : candidates)
        {
            auto total = count(nums.begin(), nums.end(), i);
            if (total > n / 3)
                ans.push_back(i);
        }
        if (ans.size() == 2 && ans[0] == ans[1])
            ans.pop_back();
        return ans;
    }
};