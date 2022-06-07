class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        vector<vector<bool> > row(9, vector<bool>(9, false));
        vector<vector<bool> > column(9, vector<bool>(9, false));
        vector<vector<bool> > block(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char ch = board[i][j];
                if (ch != '.')
                {
                    int k = (i / 3) * 3 + j / 3;
                    if (row[i][ch - '1'] || column[j][ch - '1'] || block[k][ch - '1'])
                        return false;
                    row[i][ch - '1'] = true;
                    column[j][ch - '1'] = true;
                    block[k][ch - '1'] = true;
                }
            }
        }

        return true;
    }
};