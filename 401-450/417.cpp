class Solution {
public:
    vector<int> direction{1, 0, -1, 0, 0, 1, 0, -1};
    int m, n;
    
    void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        if(visited[x][y]){
            return;
        }
        
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int newx = x + direction[2 * i], newy = y + direction[2 * i + 1];
            if(newx < m && newx >= 0 && newy < n && newy >= 0 && heights[newx][newy] >= heights[x][y]){
                dfs(newx, newy, visited, heights);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; ++i){
            dfs(i, 0, pacific, heights);
            dfs(i, n - 1, atlantic, heights);
        }
        
        for(int i = 0; i < n; ++i){
            dfs(0, i, pacific, heights);
            dfs(m - 1, i, atlantic, heights);
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};