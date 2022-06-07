class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        int i = 0;
        while (i < n)
        {
            int sum = 0;
            int j = 0;
            for (; j < n; ++j)
            {
                sum += gas[(i + j) % n];
                sum -= cost[(i + j) % n];
                if (sum < 0)
                {
                    i += j + 1;
                    break;
                }
            }
            if (j == n)
                return i;
        }
        return -1;
    }
};