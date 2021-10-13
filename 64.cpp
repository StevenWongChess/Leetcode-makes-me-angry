class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dist;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v(n, INT_MAX);
        for(int i = 0; i < m; i++){
            int left = i == 0 ? 0 : INT_MAX;
            for(int j = 0; j < n; j++){
                v[j] = min(v[j], left) + grid[i][j];
                left = v[j];
            }
        }
        return v[n - 1];
    }
};