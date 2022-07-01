class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (l < r)
        {
            if (l + 1 == r)
            {
                return (nums[l] < nums[r]) ? r : l;
            }

            int mid = (l + r) / 2;
            bool left = (mid == 0) || (nums[mid] > nums[mid - 1]);
            bool right = (mid == n - 1) || (nums[mid] > nums[mid + 1]);

            if (left && right)
            {
                return mid;
            }
            else if (left)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        return l;
    }
};