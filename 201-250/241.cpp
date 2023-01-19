class Solution {
public:
    vector<int> dfs(vector<vector<vector<int>>>& dp, vector<int>& v, int l, int r){
        if(dp[l][r].size() == 0){
            if(l == r){
                dp[l][r].push_back(v[l]);
            }
            else{
                for(int i = l; i < r; i += 2){
                    auto a = dfs(dp, v, l, i);
                    auto b = dfs(dp, v, i + 2, r);
                    for(auto c: a){
                        for(auto d: b){
                            if(v[i + 1] == -1)
                                dp[l][r].push_back(c + d);
                            else if(v[i + 1] == -2)
                                dp[l][r].push_back(c - d);
                            else
                                dp[l][r].push_back(c * d);
                        }
                    }
                }
            }
        }
        return dp[l][r];
    }

    vector<int> diffWaysToCompute(string expression) {
        // -1 add, -2 minus, -3 multi
        int n = expression.size();
        vector<int> v; 
        int num = 0;
        for(int i = 0; i < n; ++i){
            auto ch = expression[i];
            if(isdigit(ch))
                num = num * 10 + expression[i] - '0';
            else{
                v.push_back(num);
                if(ch == '+')
                    v.push_back(-1);
                else if(ch == '-')
                    v.push_back(-2);
                else
                    v.push_back(-3);
                num = 0;
            }
        }
        v.push_back(num);

        int m = v.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(m));
        return dfs(dp, v, 0, m - 1);
    }
};