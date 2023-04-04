class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long> balance;
        vector<long> v;
        for(auto& t: transactions){
            balance[t[0]] -= t[2];
            balance[t[1]] += t[2];
        }

        for(auto& [_, y]: balance){
            if(y != 0)
                v.push_back(y);
        }

        return dfs(0, v);
    }

    int dfs(int ith, vector<long>& v){
        int n = v.size();
        while(ith < n && v[ith] == 0)
            ++ith;

        int step = INT_MAX;
        for(int i = ith + 1; i < n; ++i){
            if(v[ith] * v[i] < 0){
                v[i] += v[ith];
                step = min(step, 1 + dfs(ith + 1, v));
                v[i] -= v[ith];
            }
        }
        return step == INT_MAX ? 0 : step;
    }
};