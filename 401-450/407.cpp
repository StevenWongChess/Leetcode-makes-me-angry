class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if(m <= 2 || n <= 2){
            return 0;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    pq.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int ans = 0;
        while(!pq.empty()){
            auto [x, y] = pq.top();
            pq.pop();
            for(auto [a, b]: dir){
                int nx = y / n + a, ny = y % n + b;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]){
                    ans += max(0, x - heightMap[nx][ny]);
                    visited[nx][ny] = true;
                    pq.push({max(heightMap[nx][ny], x), nx * n + ny});
                }
            }
        }
        
        return ans;
    }
};