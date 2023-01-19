class Solution {
public:
    int check(vector<vector<int>>& matrix, int mid){
        int n = matrix.size(), i = n - 1, j = 0, count = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] <= mid){
                count += i + 1;
                ++j;
            }
            else{
                --i;
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n - 1][n - 1];
        
        while(l < r){
            int mid = (r - l) / 2 + l;
            auto count = check(matrix, mid);
            if(count >= k){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        
        return l;
    }
};