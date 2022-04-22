class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>row(9, vector<int>(9, 0));
        vector<vector<int>>column(9, vector<int>(9, 0));
        vector<vector<int>>block(9, vector<int>(9, 0));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                if(ch != '.'){
                    if(row[i][ch - '1'] == 1 || column[j][ch - '1'] == 1 || block[i/3 + 3 * (j/3)][ch - '1'] == 1){
                        return false;
                    }
                    row[i][ch - '1']++;
                    column[j][ch - '1']++;
                    block[i/3 + 3 * (j/3)][ch - '1']++;
                }
            }
        }
        return true;
    }
};