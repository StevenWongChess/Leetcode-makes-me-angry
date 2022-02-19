class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O'){
            return;
        }
        board[i][j] = 'A';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for(int i = 0; i < n; i++){
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};