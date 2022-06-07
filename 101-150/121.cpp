class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX;
        int ans = 0;

        for (auto i : prices)
        {
            ans = max(ans, i - min_price);
            min_price = min(min_price, i);
        }

        return ans;
    }
};