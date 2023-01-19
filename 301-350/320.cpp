class Solution {
public:
    void dfs(vector<string>& ans, string& word, int ith, int count, string s){
        int n = word.size();
        if(ith == n){
            if(count > 0)
                s += to_string(count);
            ans.push_back(s);
            return;
        }
        dfs(ans, word, ith + 1, count + 1, s);
        dfs(ans, word, ith + 1, 0, s + (count == 0 ? "" : to_string(count)) + word[ith]);
    };

    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        dfs(ans, word, 0, 0, "");
        return ans;
    }
};