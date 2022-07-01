class Solution
{
public:
    vector<int> &v;
    Solution(vector<int> &nums) : v(nums)
    {
    }

    int pick(int target)
    {
        int n = v.size(), ans = -1;

        for (int i = 0, count = 0; i < n; ++i)
        {
            if (v[i] == target)
            {
                ++count;
                if (rand() % count == 0)
                {
                    ans = i;
                }
            }
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

class Solution
{
public:
    unordered_map<int, vector<int> > dict;
    Solution(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            dict[nums[i]].push_back(i);
        }
    }

    int pick(int target)
    {
        vector<int> &v = dict[target];
        int n = v.size();

        return v[rand() % n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */