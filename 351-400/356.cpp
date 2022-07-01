class Solution
{
public:
    bool isReflected(vector<vector<int> > &points)
    {
        unordered_map<int, set<int> > dict;
        for (auto i : points)
        {
            dict[i[0]].insert(i[1]);
        }

        auto cmp = [](vector<int> &a, vector<int> &b)
        { return a[0] < b[0]; };
        auto lIt = *min_element(points.begin(), points.end(), cmp), rIt = *max_element(points.begin(), points.end(), cmp);
        int sum = lIt[0] + rIt[0];

        for (auto i : points)
        {
            if (!dict.count(sum - i[0]) || !dict[sum - i[0]].count(i[1]))
                return false;
        }

        return true;
    }
};