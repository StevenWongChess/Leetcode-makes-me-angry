class Solution {
public:
    // struct{bool operator()(vector<int> a, vector<int> b){
    //     return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    // }} f; 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), f);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        if(intervals.size() == 0)
            return {};
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= right)
                right = max(intervals[i][1], right);
            else{
                ans.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];             
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};