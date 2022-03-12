class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        for(int i = 2; i < n; i++){
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];
            if((xi - x0) * (yi - y1) != (xi - x1) * (yi - y0))
                return false;
        }
        return true;
    }
};