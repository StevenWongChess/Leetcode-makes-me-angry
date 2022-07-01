class Solution
{
public:
    string getHash(string word)
    {
        string key;
        int n = word.size();
        for (int i = 1; i < n; ++i)
        {
            key += (word[i] - word[i - 1] + 26) % 26 + 'a';
        }

        return key;
    }

    vector<vector<string> > groupStrings(vector<string> &strings)
    {
        unordered_map<string, vector<string> > dict;
        vector<vector<string> > ans;

        for (auto word : strings)
        {
            string key = getHash(word);
            dict[key].push_back(word);
        }

        for (auto &[x, y] : dict)
        {
            ans.push_back(y);
        }

        return ans;
    }
};