class Solution {
public:
    bool dfs(int ith, vector<int>& matchsticks, vector<int>& edges, int sum){
        int n = matchsticks.size();
        if(ith == n){
            return true;
        }
        for(int i = 0; i < 4; ++i){
            edges[i] += matchsticks[ith];
            if(edges[i] <= sum && dfs(ith + 1, matchsticks, edges, sum)){
                return true;
            }
            edges[i] -= matchsticks[ith];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0){
            return false;
        }
        sum /= 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4);
        return dfs(0, matchsticks, edges, sum);
    }
};