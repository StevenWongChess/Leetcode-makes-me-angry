class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        points.push_back(points[0]);
        points.push_back(points[1]);
        int n = points.size();
        long cur, last = 0;
        
        for(int i = 0; i < n - 2; ++i){
            int x1 = points[i][0], y1 = points[i][1],
            x2 = points[i + 1][0], y2 = points[i + 1][1],
            x3 = points[i + 2][0], y3 = points[i + 2][1];
            
            int a = x2 - x1, b = y2 - y1, c = x3 - x2, d = y3 - y2;
            cur = a * d - b * c;
            if(cur == 0){
                continue;
            }
            else if(last * cur < 0){
                return false;
            }
            last = cur;
        }
        
        return true;
    }
};