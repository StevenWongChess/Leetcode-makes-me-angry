class Solution {
public:
    vector<pair<int, int>> board;
    int count = 0;
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
            count++;
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
    int totalNQueens(int n){
        dfs(0, n);
        return count;
    }
};