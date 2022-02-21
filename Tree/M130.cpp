class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;
        board[i][j] = '*';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < n; i++){
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for(int i = 0; i < m; i++){
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '*')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};