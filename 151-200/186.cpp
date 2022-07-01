class Solution
{
public:
    void reverseWords(vector<char> &s)
    {
        int n = s.size();
        reverse(s.begin(), s.end());
        int l = 0, r = 0;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + l, s.begin() + r);
                l = r = i + 1;
            }
            else
            {
                ++r;
            }
        }

        reverse(s.begin() + l, s.begin() + r);
    }
};