class Solution
{
public:
    int minCost(vector<vector<int> > &costs)
    {
        int red = 0;
        int blue = 0;
        int green = 0;
        for (auto i : costs)
        {
            int r, b, g;
            r = min(blue, green) + i[0];
            b = min(red, green) + i[1];
            g = min(blue, red) + i[2];
            red = r, blue = b, green = g;
        }
        return min(min(red, blue), green);
    }
};