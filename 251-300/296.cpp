class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> v1, v2;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    v1.push_back(i);
                }
            }
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[j][i] == 1){
                    v2.push_back(i);
                }
            }
        }
        
        int x = v1[v1.size() / 2], y = v2[v2.size() / 2], ans = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[j][i] == 1){
                    ans += abs(i - y);
                    ans += abs(j - x);
                }
            }
        }
        
        return ans;
    }
};