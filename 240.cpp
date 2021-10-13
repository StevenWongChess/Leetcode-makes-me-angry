class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = m - 1;
        while(x < n && y >= 0){
            if(matrix[y][x] == target)
                return true;
            else if(matrix[y][x] > target)
                y--;
            else
                x++;
        }
        return false;
    }
};