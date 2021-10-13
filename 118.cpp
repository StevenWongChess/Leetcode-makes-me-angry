class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {};
        if(numRows == 0)
            return ans;
        ans.push_back({1});
        for(int i = 1; i < numRows; i++){
            vector<int> line = {};
            int left = 0;
            line.push_back(1);
            for(int j = 0; j < i - 1; j++){
                line.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }
            line.push_back(1);
            ans.push_back(line);
        }
        return ans;
    }
};