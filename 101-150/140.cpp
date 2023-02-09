class Solution {
public:
    unordered_set<string> set;
    unordered_map<int, vector<string>> ans;
    void dfs(string &s, int ith){
        if(ans.count(ith))
            return;

        int n = s.size();
        if(ith == n){
            ans[ith] = {""};
            return;
        }

        ans[ith] = {};
        for(int i = ith + 1; i <= n; ++i){
            string word = s.substr(ith, i - ith);
            if(set.count(word)){
                dfs(s, i);
                for(auto next: ans[i]){
                    ans[ith].push_back(next.size() == 0 ? word : word + " " + next);
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i: wordDict)
            set.insert(i);

        dfs(s, 0);
        return ans[0];
    }
};