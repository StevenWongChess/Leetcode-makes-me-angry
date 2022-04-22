class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int first = INT_MAX;
        int second = INT_MAX;
        for (auto i : nums)
        {
            if (i > second)
                return true;
            else if (i > first)
                second = i;
            else
                first = i;
        }
        return false;
    }
};