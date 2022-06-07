class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int> dict(26, 0);
        for (auto i : magazine)
        {
            ++dict[i - 'a'];
        }
        for (auto i : ransomNote)
        {
            --dict[i - 'a'];
        }

        return *min_element(dict.begin(), dict.end()) >= 0;
    }
};