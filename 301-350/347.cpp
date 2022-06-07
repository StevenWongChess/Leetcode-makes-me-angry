class Solution
{
public:
    int partition(vector<pair<int, int> > &v, int l, int r)
    {
        int pivot = v[r].second;
        int j = l;
        for (int i = l; i <= r; ++i)
        {
            if (pivot < v[i].second)
            {
                swap(v[i], v[j]);
                ++j;
            }
        }
        swap(v[j], v[r]);
        return j;
    }

    void quicksort(vector<pair<int, int> > &v, int k, int l, int r)
    {
        int mid = partition(v, l, r);
        if (mid == k - 1)
            return;
        else if (mid < k - 1)
            quicksort(v, k, mid + 1, r);
        else
            quicksort(v, k, l, mid - 1);
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (auto i : nums)
        {
            ++freq[i];
        }
        vector<pair<int, int> > v(freq.begin(), freq.end());
        quicksort(v, k, 0, v.size() - 1);
        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (auto i : nums)
        {
            ++freq[i];
        }

        auto cmp = [](pair<int, int> &a, pair<int, int> &b)
        { return a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> pq(cmp);
        for (auto &i : freq)
        {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty())
        {
            auto [x, y] = pq.top();
            pq.pop();
            ans.push_back(x);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};