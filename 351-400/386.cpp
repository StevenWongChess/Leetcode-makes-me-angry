class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans(n);
        int it = 1;
        for (int i = 0; i < n; ++i)
        {
            ans[i] = it;
            if (it * 10 <= n)
            {
                it *= 10;
            }
            else
            {
                while (it % 10 == 9 || it + 1 > n)
                {
                    it /= 10;
                }
                ++it;
            }
        }

        return ans;
    }
};