class Solution
{
public:
    int minMeetingRooms(vector<vector<int> > &intervals)
    {
        unordered_map<int, int> dict;
        for (auto i : intervals)
        {
            dict[i[0]]++;
            dict[i[1]]--;
        }
        vector<pair<int, int> > list(dict.begin(), dict.end());
        sort(list.begin(), list.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.first < b.first; });
        int ans = 0;
        int count = 0;
        for (auto i : list)
        {
            count += i.second;
            ans = max(ans, count);
        }
        return ans;
    }
};