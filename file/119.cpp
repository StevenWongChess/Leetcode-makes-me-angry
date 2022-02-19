class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        vector<int> ans = {1, 1};
        for(int j = 2; j <= rowIndex; j++){
            for(int i = j - 1; i >= 1; i--){
                ans[i] += ans[i - 1];
            }
            ans[0] = 1;
            ans.push_back(1);
        }
        return ans;
    }
};