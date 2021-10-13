class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int length = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < m; i++){
            int left = 0; int topleft = 0;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    int topleft = min(min(dp[j + 1], dp[j]), topleft) + 1;  
                    swap(topleft, dp[j+1]);
                    length = max(length, dp[j + 1]);
                }
                else{
                    dp[j + 1] = 0;
                }
            }
        }
        return length * length;
    }
};