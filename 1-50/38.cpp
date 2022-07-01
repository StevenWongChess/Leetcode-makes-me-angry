class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";
        for (int i = 1; i < n; ++i)
        {
            string next;
            int m = ans.size();
            int count = 0, number = -1;
            for (auto j : ans)
            {
                if (j == number + '0')
                    ++count;
                else
                {
                    if (count > 0)
                    {
                        next += to_string(count) + (char)(number + '0');
                    }
                    count = 1;
                    number = j - '0';
                }
            }
            next += to_string(count) + (char)(number + '0');
            ans = next;
        }

        return ans;
    }
};