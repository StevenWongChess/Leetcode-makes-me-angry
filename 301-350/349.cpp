class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int l = 0;
        int r = 0;
        while (l < m && r < n)
        {
            if (nums1[l] == nums2[r])
            {
                if (ans.empty() || ans.back() != nums1[l])
                    ans.push_back(nums1[l]);
                l++;
                r++;
            }
            else if (nums1[l] < nums2[r])
                l++;
            else
                r++;
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1;
        unordered_set<int> set2;
        vector<int> ans;

        for (auto i : nums1)
        {
            set1.insert(i);
        }
        for (auto i : nums2)
        {
            set2.insert(i);
        }

        for (auto i : set1)
        {
            if (set2.count(i))
                ans.push_back(i);
        }

        return ans;
    }
};