class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<int> yes(k + 1, INT_MIN), no(k + 1, 0);
        for (auto j : prices)
        {
            for (int i = 1; i <= k; ++i)
            {
                yes[i] = max(yes[i], no[i - 1] - j);
                no[i] = max(no[i], yes[i] + j);
            }
        }
        return no[k];
    }
};