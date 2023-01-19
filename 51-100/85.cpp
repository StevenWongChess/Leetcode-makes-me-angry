class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> left(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '1'){
                    left[i][j] = (j == 0) ? 1: left[i][j - 1] + 1;
                }
            }
        }
         
        int ans = 0;
        for(int j = 0; j < n; ++j){
            vector<int> l(m), r(m);
            stack<int> s;
            for(int i = 0; i < m; ++i){
                while(!s.empty() && left[s.top()][j] >= left[i][j]){
                    s.pop();
                }
                l[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
            s = stack<int>();
            for(int i = m - 1; i >= 0; --i){
                while(!s.empty() && left[s.top()][j] >= left[i][j]){
                    s.pop();
                }
                r[i] = s.empty() ? m : s.top();
                s.push(i);
            }
            
            for(int i = 0; i < m; ++i){
                int height = r[i] - l[i] - 1, area = height * left[i][j];     
                ans = max(ans, area);
            }
        }
        return ans;
    }
};