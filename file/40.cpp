class Solution {
public:
    vector<vector<int>> ans;
    vector<int> line;
    vector<pair<int, int>> freq;
    void dfs(vector<int>& line, int ith, int target){
        if(target == 0){
            ans.push_back(line);
            return;
        }
        if(ith >= freq.size())
            return;
        dfs(line, ith + 1, target);
        int times = min(target / freq[ith].first, freq[ith].second);
        for(int i = 1; i <= times; i++){
            line.push_back(freq[ith].first);
            dfs(line, ith + 1, target - freq[ith].first * i);
        }
        for(int i = 1; i <= times; i++){
            line.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(auto i: candidates){
            if(freq.size() == 0 || i != freq.back().first)
                freq.push_back({i, 1});
            else
                freq.back().second++;
        }
        dfs(line, 0, target);
        return ans;
    }
};