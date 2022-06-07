class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>, less<int> > pq;
        for (auto i : stones)
        {
            pq.push(i);
        }

        while (pq.size() > 1)
        {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();

            if (a != b)
            {
                pq.push(abs(a - b));
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};