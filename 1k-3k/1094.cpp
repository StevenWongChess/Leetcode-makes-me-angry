class Solution
{
public:
    bool carPooling(vector<vector<int> > &trips, int capacity)
    {
        unordered_map<int, int> dict;

        for (auto &i : trips)
        {
            dict[i[1]] += i[0];
            dict[i[2]] -= i[0];
        }

        vector<pair<int, int> > pickup(dict.begin(), dict.end());
        sort(pickup.begin(), pickup.end(), [](pair<int, int> a, pair<int, int> b)
             { return a.first < b.first; });

        int sum = 0;
        for (auto &i : pickup)
        {
            sum += i.second;
            if (sum > capacity)
                return false;
        }

        return true;
    }
};