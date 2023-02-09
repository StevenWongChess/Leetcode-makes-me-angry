class Solution {
public:
    void dfs(vector<vector<int>>& next, vector<bool>& visit, int x, int cnt, int& ans, int m, int n){
        if(cnt >= m && cnt <= n)
            ++ans;
        if(cnt >= n)
            return;

        for(auto i: next[2 * x]){
            if(!visit[i]){
                visit[i] = true;
                dfs(next, visit, i, cnt + 1, ans, m, n);
                visit[i] = false;
            }
        }

        for(auto i: next[2 * x + 1]){
            if(!visit[i] && visit[(x + i) / 2]){
                visit[i] = true;
                dfs(next, visit, i, cnt + 1, ans, m, n);
                visit[i] = false;
            }
        }
    }

    int numberOfPatterns(int m, int n) {
        vector<vector<int>> next = {
            {1,2,3,4,5,6,7,8,9},{},
            {2,4,5,6,8},{3,7,9},
            {1,3,4,5,6,7,9},{8},
            {2,4,5,6,8},{1,7,9},
            {1,2,3,5,7,8,9},{6},
            {1,2,3,4,6,7,8,9},{},
            {1,2,3,5,7,8,9},{4},
            {2,4,5,6,8},{1,3,9},
            {1,3,4,5,6,7,9},{2},
            {2,4,5,6,8},{1,3,7}
        };
        vector<bool> visit(10, false);
        int ans = 0;
        dfs(next, visit, 0, 0, ans, m, n);        
        return ans;
    }
};