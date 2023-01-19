class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antidiagonal;

    TicTacToe(int n) {
        rows.assign(n, 0);
        cols.assign(n, 0);
        diagonal = 0;
        antidiagonal = 0;
    }
    
    int move(int row, int col, int player) {
        int n = rows.size();
        int currPlayer = (player == 1) ? 1 : -1;
        rows[row] += currPlayer;
        cols[col] += currPlayer;
        if (row == col) diagonal += currPlayer;
        if (row == n - col - 1) antidiagonal += currPlayer;

        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(antidiagonal) == n){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */