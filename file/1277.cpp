class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < m; i++){
            int lefttop = 0;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    lefttop = min(min(dp[j], dp[j + 1]), lefttop) + 1;
                    count += lefttop;
                    swap(lefttop, dp[j + 1]);
                }
                else{
                    dp[j + 1] = 0;
                }
            } 
        }
        return count;
    }
};