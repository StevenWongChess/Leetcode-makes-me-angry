class WordDistance
{
public:
    unordered_map<string, vector<int> > dict;
    WordDistance(vector<string> &wordsDict)
    {
        int n = wordsDict.size();
        for (int i = 0; i < n; ++i)
        {
            if (dict.count(wordsDict[i]))
            {
                dict[wordsDict[i]].push_back(i);
            }
            else
            {
                dict[wordsDict[i]] = {i};
            }
        }
    }

    int shortest(string word1, string word2)
    {
        int m = dict[word1].size(), n = dict[word2].size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        while (i < m && j < n)
        {
            ans = min(ans, abs(dict[word1][i] - dict[word2][j]));
            if (dict[word1][i] < dict[word2][j])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }

        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */