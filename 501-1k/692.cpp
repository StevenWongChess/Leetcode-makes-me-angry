class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> dict;
        for (auto i : words)
        {
            ++dict[i];
        }

        auto fun = [](pair<string, int> &a, pair<string, int> &b)
        { return a.second != b.second ? a.second > b.second : a.first < b.first; };
        priority_queue<pair<string, int>, vector<pair<string, int> >, decltype(fun)> pq(fun);

        for (auto &i : dict)
        {
            pq.push(i);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<string> ans(k);
        for (int i = k - 1; i >= 0; --i)
        {
            ans[i] = pq.top().first;
            pq.pop();
        }

        return ans;
    }
};