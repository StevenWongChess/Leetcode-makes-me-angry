class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n);
        
        for(int i = 0; i < n; ++i){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int idx = s.top();
                ans[idx] = i - idx;
                s.pop();
            }
            s.push(i);
        }
        
        return ans;
    }
};