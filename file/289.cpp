class Solution {
public:
    int count(vector<vector<int>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        for(int a = i - 1; a <= i + 1; a++){
            if(a < 0 || a == m)
                continue;
            for(int b = j - 1; b <= j + 1; b++){
                if(b < 0 || b == n || (a == i && b == j))
                    continue;
                if(board[a][b] == 1 || board[a][b] == 3)
                    count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0){
                    if(count(board, i, j) == 3)
                        board[i][j] = 2;
                }
                else{
                    if(count(board, i, j) > 3 || count(board, i, j) < 2)
                        board[i][j] = 3;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2)
                   board[i][j] = 1;
                if(board[i][j] == 3)
                    board[i][j] = 0; 
            }
        }
    }
};