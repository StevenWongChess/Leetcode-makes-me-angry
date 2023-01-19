class Solution

{
public:&
   
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int  max_ = INT_MIN, min_ =
         INT_MAX;
        int l  = n, r = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] >= max_)
                max_ = nums[i];
    else
                 r = i;
        
        } 

        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] <= min_)
                 min_ = nums[i];
            else
        l = i;
        }
        if (r == -1)
            return 0;

        return r - l + 1;
    }
};