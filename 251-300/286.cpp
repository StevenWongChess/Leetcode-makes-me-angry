class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<int> direction = {1, 0, -1, 0, 0, 1, 0, -1};
        int m = rooms.size(), n = rooms[0].size();
        
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(rooms[i][j] == 0){
                    q.push({i, j, 0});
                }
            }
        }
        
        while(!q.empty()){
            auto [x, y, d] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++i){
                int newx = x + direction[2 * i], newy = y + direction[2 * i + 1];
                if(newx >= 0 && newx< m && newy >= 0 && newy < n && rooms[newx][newy] > d + 1){
                    rooms[newx][newy] = d + 1;
                    q.push({newx, newy, d+ 1});
                }
            }
        }
    }
};