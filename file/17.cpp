class Solution {
public:
    vector<string> ans;
    string s;
    vector<string> dict{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string digits, int ith){
        if(ith == digits.length()){
            ans.push_back(s);
            return;
        }
        for(auto i: dict[digits[ith] - '2']){
            s += i;
            dfs(digits, ith + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return ans;
        }
        dfs(digits, 0);
        return ans;
    }
};