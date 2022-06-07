class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        int n = nums2.size();
        int l = 0;
        int r = 0;
        while (l < m && r < n)
        {
            if (nums1[l] == nums2[r])
            {
                ans.push_back(nums1[l]);
                l++;
                r++;
            }
            else if (nums1[l] > nums2[r])
                r++;
            else
                l++;
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> dict1;
        unordered_map<int, int> dict2;
        vector<int> ans;

        for (auto i : nums1)
        {
            ++dict1[i];
        }
        for (auto i : nums2)
        {
            ++dict2[i];
        }

        for (auto &[x, y] : dict1)
        {
            if (dict2.count(x))
            {
                for (int i = 0; i < min(y, dict2[x]); ++i)
                {
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};