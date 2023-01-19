class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]){
                    for(auto [x, y]: dir){
                        int n_x = i + x, n_y = j + y;
                        if(n_x < 0 || n_x >= m || n_y < 0 || n_y >=n || !grid[n_x][n_y]){
                            ++ans;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};