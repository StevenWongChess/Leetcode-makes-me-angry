class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> fact(n + 1);
        vector<int> ith;
        vector<bool> visited(n, false);
        fact[0] = 1;
        for(int i = 1; i <= n; ++i)
            fact[i] = i * fact[i - 1];
        --k;
        for(int i = n - 1; i >= 1; --i){
            ith.push_back(k / fact[i]);
            k %= fact[i];
        }
        ith.push_back(0);
        for(int i = 0; i < n; ++i){
            int count = 0;
            for(int j = 0; j < n; ++j){
                if(!visited[j]){
                    ++count;
                }
                if(count == ith[i] + 1){
                    visited[j] = true;
                    ans += '1' + j;
                    break;
                }
            }
        }
        return ans;
    }
};