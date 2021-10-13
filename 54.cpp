class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        while(i <= m - 1 - i && i <= n - 1 - i){
            for(int x = i; x <= n - i - 1; x++){
                ans.push_back(matrix[i][x]);
            }
            for(int y = i + 1; y <= m - i - 2; y++){
                ans.push_back(matrix[y][n - 1 - i]);
            }
            if(i < m - 1 - i){
                for(int x = n - i - 1; x >= i; x--){
                    ans.push_back(matrix[m - 1 - i][x]);
                }
            }
            if(i < n - 1 - i){
                for(int y = m - i - 2; y >= i + 1; y--){
                    ans.push_back(matrix[y][i]);
                }
            }
            i++;
        }
        return ans;
    }
};