class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        for(int i = 0; i < n; i++){
            int m = ans.size();
            for(int i = 0; i < m; i++){
                ans.push_back(ans[m - 1 - i] + m);
            }
        }
        return ans;
    }
};