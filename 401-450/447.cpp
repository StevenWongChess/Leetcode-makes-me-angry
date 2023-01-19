class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        
        for(int i = 0; i < n; ++i){
            unordered_map<int, int> dict;
            for(int j = 0; j < n; ++j){
                int x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
                int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                ++dict[dist];
            }
            for(auto [x, y]: dict){
                ans += y * (y - 1);
            }
        }
        
        return ans;
    }
};