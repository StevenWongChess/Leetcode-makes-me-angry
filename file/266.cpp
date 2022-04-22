class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        vector<int> dict(26);
        int n = s.length();
        for (auto i : s)
        {
            dict[i - 'a']++;
        }
        int count = 0;
        for (auto i : dict)
        {
            if (i % 2 == 1)
            {
                count++;
            }
            if (count > 1 || (count > 1 && n % 2 == 0))
                return false;
        }
        return true;
    }
};