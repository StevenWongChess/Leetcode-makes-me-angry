class Solution
{
public:
    int getID(int x, int w)
    {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }

    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        unordered_map<int, int> bucket;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            long x = nums[i];
            int id = getID(x, t + 1ll);
            if (bucket.count(id) || (bucket.count(id - 1) && abs(x - bucket[id - 1]) <= t) || (bucket.count(id + 1) && abs(x - bucket[id + 1]) <= t))
                return true;

            bucket[id] = nums[i];
            if (i >= k)
            {
                bucket.erase(getID(nums[i - k], t + 1ll));
            }
        }

        return false;
    }
};

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            auto bs = s.lower_bound(max(INT_MIN + t, nums[i]) - t);
            if (bs != s.end() && *bs <= min(INT_MAX - t, nums[i]) + t)
                return true;

            s.insert(nums[i]);
            if (i >= k)
            {
                s.erase(nums[i - k]);
            }
        }

        return false;
    }
};