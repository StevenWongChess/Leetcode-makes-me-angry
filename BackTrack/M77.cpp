class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void dfs(int end, int k, int n){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        for(int i = end + 1; i <= n; i++){
            v.push_back(i);
            dfs(i, k, n);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(0, k, n);
        return ans;
    }
};