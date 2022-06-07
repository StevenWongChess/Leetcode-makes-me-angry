class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> dict;

        for (auto i : arr)
        {
            ++dict[i];
        }

        unordered_map<int, bool> freq;

        for (auto &[x, y] : dict)
        {
            if (freq.count(y))
                return false;
            freq[y] = true;
        }

        return true;
    }
};