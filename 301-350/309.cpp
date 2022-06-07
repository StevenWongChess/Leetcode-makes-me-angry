class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int yes = INT_MIN;
        int no_before = 0;
        int no = 0;

        for (auto i : prices)
        {
            int tmp = no_before;
            no_before = max(no_before, no);
            no = max(no, yes + i);
            yes = max(yes, tmp - i);
        }

        return no;
    }
};