class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > ans;
        ans.push_back({1});
        vector<int> line = {1};
        for (int i = 1; i < numRows; ++i)
        {
            int prev = 0;
            for (int j = i - 1; j > 0; --j)
            {
                line[j] += line[j - 1];
            }
            line.emplace_back(1);
            ans.emplace_back(line);
        }
        return ans;
    }
};