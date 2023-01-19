class Solution {
public:
    bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<int> start, vector<int> dest){
        int m = maze.size(), n = maze[0].size();
        int a = start[0], b = start[1], c = dest[0], d = dest[1];
        int dx = 0;
        if(visited[a][b])
            return false;
        visited[a][b] = true;
        if(a == c && b == d)
            return true;
        while(a + dx + 1 < m && maze[a + dx + 1][b] == 0)
            ++dx;
        if(dfs(maze, visited, {a + dx, b}, dest))
            return true;
        dx = 0;

        while(a - dx - 1 >= 0 && maze[a - dx - 1][b] == 0)
            ++dx;
        if(dfs(maze, visited, {a - dx, b}, dest))
            return true;
        dx = 0;

        while(b + dx + 1 < n && maze[a][b + dx + 1] == 0)
            ++dx;
        if(dfs(maze, visited, {a, b + dx}, dest))
            return true;
        dx = 0;

        while(b - dx - 1 >= 0 && maze[a][b - dx - 1] == 0)
            ++dx;
        if(dfs(maze, visited, {a, b - dx}, dest))
            return true;
        dx = 0;
        return false;
    };

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(maze, visited, start, destination);
    }
};