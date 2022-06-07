class Solution
{
public:
    int countPairs(vector<int> &deliciousness)
    {
        vector<int> pow2;
        unordered_map<int, int> dict;
        int ans = 0;
        int it = 1;
        for (int i = 0; i <= 21; i++)
        {
            pow2.push_back(it);
            it *= 2;
        }

        for (auto i : deliciousness)
        {
            if (dict.count(i) > 0)
            {
                ans += dict[i];
                ans %= 1000000007;
            }
            for (auto j : pow2)
            {
                if (i <= j)
                {
                    ++dict[j - i];
                }
            }
        }

        return ans;
    }
};