class Solution {
public:
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    void bfs(vector<vector<int>>& total, vector<vector<int>>& grid, int i, int j, int empty_value){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        int step = 0;

        while(!q.empty()){
            int size = q.size();
            ++step;
            for(int k = 0; k < size; ++k){
                auto [x, y] = q.front();
                q.pop();

                for(auto [dx, dy]: directions){
                    int newx = x + dx, newy = y + dy;
                    if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == empty_value){
                        --grid[newx][newy];
                        total[newx][newy] += step;
                        q.push({newx, newy});
                    }
                }
            }
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> total(m, vector<int>(n, 0));
        int empty_value = 0, ans = INT_MAX;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    bfs(total, grid, i, j, empty_value);
                    --empty_value;
                }
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == empty_value){
                    ans = min(ans, total[i][j]);
                }
                // cout << total[i][j] << ", ";
            }
            // cout << endl;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};