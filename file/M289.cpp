class Solution {
public:
    int m; int n;
    int search(vector<vector<int>>& board, int a, int b){
        int ans = 0;
        for(int i = a - 1; i <= a + 1; i++){
            if(i < 0 || i >= m)
                continue;
            for(int j = b - 1; j <= b + 1; j++){
                if(j < 0 || j >= n || (i == a && j == b)){
                   continue;
                }
                if(board[i][j] == 1 || board[i][j] == 3)
                   ans++;
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(); 
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int count = search(board, i, j);
                if(board[i][j] == 1){
                    board[i][j] = (count == 2 || count == 3) ? 1 : 3;
                }
                else{
                    board[i][j] = (count == 3) ? 2 : 0;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 3)
                    board[i][j] = 0;
                else if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};