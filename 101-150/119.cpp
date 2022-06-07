class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans = {1};
        for (int i = 1; i <= rowIndex; i++)
        {
            for (int j = i - 1; j > 0; --j)
            {
                ans[j] += ans[j - 1];
            }
            ans.push_back(1);
        }
        return ans;
    }
};