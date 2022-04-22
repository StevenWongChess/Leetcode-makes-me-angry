class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int begin = newInterval[0];
        int end = newInterval[1];
        for(int i = 0; i < n; i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(end < l){
                ans.push_back({begin, end});
                begin = l;
                end = r;
            }
            else if(r < begin){
                ans.push_back({l, r});
            }
            else{
                begin = min(begin, l);
                end = max(end, r);
            }
        }
        ans.push_back({begin, end});
        return ans;
    }
};