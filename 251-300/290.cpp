class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        int n = pattern.size(), it = 0;
        vector<string> words;
        stringstream ss(s);
        unordered_map<char, string> dict1;
        unordered_map<string, char> dict2;

        while (ss)
        {
            string word;
            ss >> word;
            words.push_back(word);
        }

        words.pop_back();

        if (words.size() != n)
            return false;

        for (int i = 0; i < n; ++i)
        {
            if (dict1.count(pattern[i]) && dict1[pattern[i]] != words[i])
                return false;
            if (dict2.count(words[i]) && dict2[words[i]] != pattern[i])
                return false;
            dict1[pattern[i]] = words[i];
            dict2[words[i]] = pattern[i];
        }

        return true;
    }
};