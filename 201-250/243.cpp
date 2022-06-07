class Solution
{
public:
    int shortestDistance(vector<string> &wordsDict, string word1, string word2)
    {
        int n = wordsDict.size();
        int l = -1, r = -1;
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            if (word1 == wordsDict[i])
            {
                l = i;
                if (r != -1)
                {
                    ans = min(ans, l - r);
                }
            }
            else if (word2 == wordsDict[i])
            {
                r = i;
                if (l != -1)
                {
                    ans = min(ans, r - l);
                }
            }
        }

        return ans;
    }
};