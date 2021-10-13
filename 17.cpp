class Solution {
public:
    unordered_map<char, string> dict = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> ans;
    string line;

    void dfs(string digits, int i){
        if(i >= digits.length())
            ans.push_back(line);
        for(auto c: dict[digits[i]]){
            line += c;
            dfs(digits, i + 1);
            line.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return ans;     
        dfs(digits, 0);
        return ans;
    }
};