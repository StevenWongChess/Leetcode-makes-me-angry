class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int yes1 = INT_MIN;
        int no1 = 0;
        int yes2 = INT_MIN;
        int no2 = 0;

        for (auto i : prices)
        {
            yes1 = max(yes1, -i);
            no1 = max(no1, yes1 + i);
            yes2 = max(yes2, no1 - i);
            no2 = max(no2, yes2 + i);
        }
        return no2;
    }
};