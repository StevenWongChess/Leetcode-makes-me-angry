class Solution
{
public:
    int l, r;
    vector<int> blist;

    Solution(int n, vector<int> &blacklist)
    {
        r = blacklist.size(), l = n - r;
        blist = blacklist;
        sort(blist.begin(), blist.end());
    }

    int pick()
    {
        int k = rand() % l, left = 0, right = r - 1;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (blist[mid] - mid <= k)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left == right && blist[left] - left <= k ? k + left + 1 : k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */

class Solution
{
public:
    unordered_map<int, int> w;
    int l, r;

    Solution(int n, vector<int> &blacklist)
    {
        r = blacklist.size(), l = n - r;
        unordered_map<int, bool> dict;
        for (auto &i : blacklist)
        {
            if (i >= l)
            {
                dict[i] = true;
            }
        }

        int it = l;
        for (auto &i : blacklist)
        {
            if (i >= l)
                continue;
            while (dict[it])
            {
                ++it;
            }

            w[i] = it;
            ++it;
        }
    }

    int pick()
    {
        int k = rand() % l;
        return w.count(k) ? w[k] : k;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */