class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        for(int i = 0; i <= min(m, n) - 1 - i; i++){
            for(int j = i; j < n - i; j++){
                ans.push_back(matrix[i][j]);
            }
            for(int j = i + 1; j < m - 1 - i; j++){
                ans.push_back(matrix[j][n - 1 - i]);
            }
            if(i < m - 1 - i){
                for(int j = n - 1 - i; j >= i; j--){
                    ans.push_back(matrix[m - 1 - i][j]);
                }
            }
            if(i < n - 1 - i){
                for(int j = m - 2 - i; j >= i + 1; j--){
                    ans.push_back(matrix[j][i]);
                }
            }
        }
        return ans;
    }
};