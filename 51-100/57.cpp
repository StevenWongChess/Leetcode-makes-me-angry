class Solution
{
public:
    vector<vector<int> > insert(vector<vector<int> > &intervals, vector<int> &newInterval)
    {
        vector<vector<int> > ans;
        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];

        for (auto &i : intervals)
        {
            auto x = i[0], y = i[1];
            if (end < x)
            {
                ans.push_back({start, end});
                start = x;
                end = y;
            }
            else if (start > y)
            {
                ans.push_back({x, y});
            }
            else
            {
                start = min(start, x);
                end = max(end, y);
            }
        }

        ans.push_back({start, end});
        return ans;
    }
};