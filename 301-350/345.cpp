class Solution
{
public:
    bool isVowel(char ch)
    {
        string s = "AEIOUaeiou";
        for (auto i : s)
        {
            if (i == ch)
                return true;
        }
        return false;
    }

    string reverseVowels(string s)
    {
        int n = s.length();
        int l = 0, r = n - 1;

        while (l < r)
        {
            if (!isVowel(s[l]))
                ++l;
            else if (!isVowel(s[r]))
                --r;
            else
            {
                swap(s[l], s[r]);
                ++l;
                --r;
            }
        }
        return s;
    }
};