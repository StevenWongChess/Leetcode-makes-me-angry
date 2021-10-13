class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int size = matrix.size() * n;
        int left = 0;
        int right = size - 1;
        while(left <= right){
            int mid =  ((right - left) >> 1) + left;
            int comp = matrix[mid / n][mid % n];
            if(comp == target)
                return true;
            else if(comp > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};