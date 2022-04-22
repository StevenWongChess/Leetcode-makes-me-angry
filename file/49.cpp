class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> dict;
        for(auto s: strs){
            auto tmp = s;
            sort(tmp.begin(), tmp.end());
            dict[tmp].push_back(s);
        }
        for(auto [x, y]: dict){
            ans.push_back(y);
        }
        return ans;
    }
};