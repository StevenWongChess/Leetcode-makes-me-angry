class Solution
{
public:
    bool isVowel(char c)
    {
        for (auto i : "aeiou")
        {
            if (i == c)
                return true;
        }
        return false;
    }

    int maxVowels(string s, int k)
    {
        int n = s.length();
        int count = 0, ans = 0;

        for (int i = 0; i < n; ++i)
        {
            if (isVowel(s[i]))
                ++count;
            if (i >= k && isVowel(s[i - k]))
                --count;
            ans = max(ans, count);
        }

        return ans;
    }
};