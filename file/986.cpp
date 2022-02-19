class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int m = firstList.size(); int n = secondList.size();
        int l = 0; int r = 0;
        while(l < m && r < n){
            int a = max(firstList[l][0], secondList[r][0]);
            int b = min(firstList[l][1], secondList[r][1]);
            if(a <= b)
                ans.push_back({a, b});
            if(firstList[l][1] < secondList[r][1])
                l++;
            else
                r++;
        }
        return ans;
    }
};