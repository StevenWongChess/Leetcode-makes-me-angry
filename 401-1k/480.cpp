class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> ans;
        multiset<int> s(nums.begin(), nums.begin() + k);
        auto l = s.begin();
        // auto l = next(s.begin(), k / 2);
        for (int i = 0; i < (k - 1) / 2; i++)
        {
            l++;
        }

        int n = nums.size();
        for (int i = k; i < n + 1; ++i)
        {
            auto r = l;
            if (k % 2 == 0)
                ++r;
            ans.push_back(*l / 2.0 + *r / 2.0);
            if (i == n)
            {
                break;
            }
            s.insert(nums[i]);
            if (nums[i] < *l)
                l--;
            if (nums[i - k] <= *l)
                l++;
            s.erase(s.lower_bound(nums[i - k]));
        }

        return ans;
    }
};