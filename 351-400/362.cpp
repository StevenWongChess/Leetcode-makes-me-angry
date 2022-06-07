class HitCounter
{
public:
    deque<pair<int, int> > q;

    HitCounter()
    {
    }

    void hit(int timestamp)
    {
        if (!q.empty() && q.back().first == timestamp)
        {
            ++q.back().second;
        }
        else
        {
            q.push_back({timestamp, 1});
        }
    }

    int getHits(int timestamp)
    {
        while (!q.empty() && q.front().first <= timestamp - 300)
        {
            q.pop_front();
        }
        int ans = 0;
        for (auto [x, y] : q)
        {
            ans += y;
        }
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */