class Solution
{
public:
    unordered_map<char, int> dict = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int romanToInt(string s)
    {
        int ans = 0;
        int prev = 1001;
        for (auto i : s)
        {
            ans += dict[i];
            if (dict[i] > prev)
            {
                ans -= 2 * prev;
            }
            prev = dict[i];
        }
        return ans;
    }
};