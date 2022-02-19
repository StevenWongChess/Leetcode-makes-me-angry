class Solution {
public:
    vector<pair<int, int>> board;
    vector<vector<string>> ans;
    bool valid(int i, int j){
        for(auto [x, y]: board){
            if(x == i || y == j || x + y == i + j || x + j == y + i){
                return false;
            }
        }
        return true;
    }
    void dfs(int ith, int n){
        if(ith == n){
            vector<string> s;
            for(int i = 0; i < n; i++){
                string tmp(n, '.');
                tmp[board[i].second] = 'Q';
                s.push_back(tmp);
            }
            ans.push_back(s);
            return;
        }
        for(int i = 0; i < n; i++){
            if(valid(ith, i)){
                board.push_back({ith, i});
                dfs(ith + 1, n);
                board.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        dfs(0, n);
        return ans;
    }
};