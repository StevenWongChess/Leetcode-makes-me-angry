class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size(), l = 0, r = n - 1;
        int l_max = 0, r_max = 0;

        while (l < r)
        {
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);

            if (height[l] < height[r])
            {
                ans += l_max - height[l];
                ++l;
            }
            else
            {
                ans += r_max - height[r];
                --r;
            }
        }

        return ans;
    }
};