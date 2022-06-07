class Solution
{
public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        int m = board.size(), n = board[0].size();
        if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] != 'O')
            return;
        board[i][j] = '*';
        vector<pair<int, int>> direction = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}};
        for (auto &[x, y] : direction)
        {
            dfs(board, i + x, j + y);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }

        for (int i = 0; i < n; ++i)
        {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == '*')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};