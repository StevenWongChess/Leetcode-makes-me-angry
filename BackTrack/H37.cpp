class Solution {
public:
    int n = 9;
    vector<vector<bool>> row;
    vector<vector<bool>> column;
    vector<vector<bool>> block;
    bool dfs(vector<vector<char>>& board){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.'){
                    for(int k = 0; k < n; k++){
                        if(row[i][k] || column[j][k] || block[3 * (i / 3) + (j / 3)][k])
                            continue;
                        else{
                            board[i][j] = ('1' + k);
                            row[i][k] = true;
                            column[j][k] = true;
                            block[3 * (i / 3) + (j / 3)][k] = true;
                            if(dfs(board))
                                return true;
                            board[i][j] = '.';
                            row[i][k] = false;
                            column[j][k] = false;
                            block[3 * (i / 3) + (j / 3)][k] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board){
        row = vector<vector<bool>>(n, vector<bool>(n, false));  
        column = vector<vector<bool>>(n, vector<bool>(n, false));
        block = vector<vector<bool>>(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] != '.'){
                    int k = board[i][j] - '1';
                    row[i][k] = true;
                    column[j][k] = true;
                    block[3 * (i / 3) + (j / 3)][k] = true;
                }
            }
        }
        dfs(board);
    }
};

class Solution {
public:
    int n = 9;
    bool safe(vector<vector<char>>& board, char ch, int i, int j){
        for(int k = 0; k < n; k++){
            if(board[i][k] == ch)
                return false;
            if(board[k][j] == ch)
                return false;
            if(board[i/3 * 3 + k%3][j/3 * 3 + k/3] == ch)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.'){
                    for(int k = 1; k <= n; k++){
                        char ch = (k + '0');
                        if(safe(board, ch, i, j)){
                            board[i][j] = ch;
                            if(solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }
};