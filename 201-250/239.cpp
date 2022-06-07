class MonotonicQueue
{
    deque<int> q;

public:
    void push(int v)
    {
        while (!q.empty() && v > q.back())
        {
            q.pop_back();
        }
        q.push_back(v);
    }

    void pop()
    {
        q.pop_front();
    }

    int max()
    {
        return q.front();
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        MonotonicQueue q;
        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            q.push(nums[i]);
            if (i >= k - 1)
            {
                ans.push_back(q.max());
                if (q.max() == nums[i - k + 1])
                {
                    q.pop();
                }
            }
        }

        return ans;
    }
};