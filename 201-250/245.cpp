class Solution
{
public:
    int shortestWordDistance(vector<string> &wordsDict, string word1, string word2)
    {
        int ans = INT_MAX;
        int n = wordsDict.size();

        if (word1 == word2)
        {
            int last = -1;
            for (int i = 0; i < n; ++i)
            {
                if (wordsDict[i] == word1)
                {
                    if (last != -1)
                        ans = min(ans, i - last);
                    last = i;
                }
            }
        }
        else
        {
            int l = -1, r = -1;
            for (int i = 0; i < n; ++i)
            {
                if (wordsDict[i] == word1)
                {
                    if (r != -1)
                        ans = min(ans, i - r);
                    l = i;
                }
                else if (wordsDict[i] == word2)
                {
                    if (l != -1)
                        ans = min(ans, i - l);
                    r = i;
                }
            }
        }

        return ans;
    }
};