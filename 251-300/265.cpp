class Solution
{
public:
    int minCostII(vector<vector<int> > &costs)
    {
        int n = costs.size(), k = costs[0].size();
        vector<int> total(k, 0);

        for (auto i : costs)
        {
            int min1 = INT_MAX, min2 = INT_MAX;
            int index1 = -1, index2 = -1;
            for (int j = 0; j < k; ++j)
            {
                if (total[j] < min1)
                {
                    min2 = min1;
                    min1 = total[j];
                    index2 = index1;
                    index1 = j;
                }
                else if (total[j] < min2)
                {
                    min2 = total[j];
                    index2 = j;
                }
            }

            for (int j = 0; j < k; ++j)
            {
                total[j] = (index1 == j ? min2 : min1) + i[j];
            }
        }

        return *min_element(total.begin(), total.end());
    }
};