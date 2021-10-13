class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int left = newInterval[0];
        int right = newInterval[1];
        for(int i = 0; i < n; i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(l > right){
                ans.push_back({left, right});
                left = l; right = r;
            }
            else if(r < left){
                ans.push_back({l, r});
            }
            else{
                left = min(l, left);
                right = max(r, right);
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};