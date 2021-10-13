class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        int height = grid.size();
        int width = grid[0].size();
        if(i < 0 || i >= height || j < 0 || j >= width || grid[i][j] == '0')
            return;
        else{
            grid[i][j] = '0';
            dfs(i+1, j, grid);
            dfs(i-1, j, grid);
            dfs(i, j+1, grid);
            dfs(i, j-1, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int count = 0;
        for(auto i = 0; i < height; i++){
            for(auto j = 0; j < width; j++){
                if(grid[i][j] == '1'){
                    count ++;
                    dfs(i,j, grid);
                }
            }
        }
        return count;
    }
};