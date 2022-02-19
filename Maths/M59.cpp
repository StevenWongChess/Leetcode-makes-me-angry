class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int count = 0;
        for(int i = 0; i <= n - 1 - i; i++){
            for(int j = i; j < n - i; j++){
                count++;
                ans[i][j] = count;
            }
            for(int j = i + 1; j < n - 1 - i; j++){
                count++;
                ans[j][n - 1 - i] = count;
            }
            if(i < n - 1 - i){
                for(int j = n - 1 - i; j >= i; j--){
                    count++;
                    ans[n - 1 - i][j] = count;
                }
            }
            if(i < n - 1 - i){
                for(int j = n - 2 - i; j >= i + 1; j--){
                    count++;
                    ans[j][i] = count;
                }
            }
        }
        return ans;
    }
};