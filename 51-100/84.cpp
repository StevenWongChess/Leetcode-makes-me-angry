class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> l(n), r(n);
        for(int i = 0; i < n; ++i){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            l[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        s = stack<int>();
        for(int i = n - 1; i >= 0; --i){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            r[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(ans, (r[i] - l[i] - 1) * heights[i]);
        }
        return ans;
    }
};