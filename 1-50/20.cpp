class Solution
{
public:
    unordered_map<char, int> dict = {
        {'(', 0},
        {'[', 1},
        {'{', 2},
        {'}', 3},
        {']', 4},
        {')', 5},
    };
    bool isValid(string s)
    {
        stack<int> line;

        for (auto i : s)
        {
            auto n = dict[i];
            if (n < 3)
            {
                line.push(n);
            }
            else
            {
                if (line.empty())
                    return false;
                auto t = line.top();
                if (n + t == 5)
                {
                    line.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return line.empty();
    }
};