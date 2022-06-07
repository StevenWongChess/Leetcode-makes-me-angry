class Solution
{
public:
    int m, n;

    bool dfs(vector<vector<char> > &board, int i, int j, string &word, int ith)
    {
        int p = word.length();
        char ch = board[i][j];
        if (ch != word[ith])
            return false;
        if (word[ith] != ch)
            return false;
        if (ith >= p - 1)
            return true;
        board[i][j] = '*';

        if (i > 0 && dfs(board, i - 1, j, word, ith + 1))
            return true;
        if (i < m - 1 && dfs(board, i + 1, j, word, ith + 1))
            return true;
        if (j > 0 && dfs(board, i, j - 1, word, ith + 1))
            return true;
        if (j < n - 1 && dfs(board, i, j + 1, word, ith + 1))
            return true;

        board[i][j] = ch;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word)
    {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};