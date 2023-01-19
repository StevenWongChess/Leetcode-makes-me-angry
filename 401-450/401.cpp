class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> ans;
        for (int i = 0; i <= 11; ++i)
        {
            int l = __builtin_popcount(i);
            if (l > turnedOn)
                continue;
            for (int j = 0; j <= 59; ++j)
            {
                int r = __builtin_popcount(j);
                if (l + r == turnedOn)
                {
                    string line = to_string(i) + ":" + ((j < 10) ? ("0" + to_string(j)) : to_string(j));
                    ans.push_back(line);
                }
            }
        }

        return ans;
    }
};