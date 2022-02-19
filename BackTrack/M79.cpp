class Solution {
public:
    int m, n;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int ith){
        if(word[ith] != board[i][j]){
            return false;
        }
        else{
            if(ith == word.length() - 1)
                return true;
            // visited[i][j] = true;
            char c = board[i][j];
            board[i][j] = '*';
            bool left = (j > 0) ? dfs(board, word, i, j - 1, ith + 1) : false;
            if(left)
                return true;
            bool right = (j < n - 1) ? dfs(board, word, i, j + 1, ith + 1) : false;
            if(right)
                return true;
            bool up = (i > 0) ? dfs(board, word, i - 1, j, ith + 1) : false;
            if(up)
                return true;
            bool down = (i < m - 1) ? dfs(board, word, i + 1, j, ith + 1) : false;
            if(down)
                return true;
            board[i][j] = c;
            // visited[i][j] = false;
            return false;
            // return left || right || up || down;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        // vector<vector<int>> visited(m, vector<int>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // cout << i << " " << j << endl;
                bool ret = dfs(board, word, i, j, 0);
                if(ret)
                    return true;
            }
        }
        return false;
    }
};



class Solution {
public:
string wrd;
vector<vector<char>> brd;
vector<vector<vector<bool>>> bigfail;
    bool deal(int x,int y, int st)
    {
        if(bigfail[x][y][st])
            return false;
        if(brd[x][y]==0)
            return false;
        if(brd[x][y]!=wrd[st]) 
            return !(bigfail[x][y][st]=true);
        if(st==wrd.size()-1)
            return true;
        char c=brd[x][y];
        brd[x][y]=0;
        int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
        bigfail[x][y][st]=true;
        for(int i=0;i<4;++i)
        {
            int cx=x+dx[i],cy=y+dy[i];
            if (cx>=0 && cy>=0 && cx<brd.size() && cy<brd[0].size())
            {
                if(deal(cx,cy,st+1))
                    return true;
                bigfail[x][y][st]=bigfail[x][y][st]&&bigfail[cx][cy][st+1];
            }
        }
        brd[x][y]=c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        brd=move(board);
        wrd=word;
        bigfail.resize(brd.size(),vector<vector<bool>>(brd[0].size(),vector<bool>(word.size())));
        for(int i=0;i<brd.size();++i)
            for(int j=0;j<brd[0].size();++j)
                if(deal(i,j,0))
                    return true;
        return false;
    }
};
