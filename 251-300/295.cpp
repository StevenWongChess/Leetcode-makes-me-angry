class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int> > minq;
    priority_queue<int, vector<int>, less<int> > maxq;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        int n = minq.size() + maxq.size();
        if (n == 0)
        {
            maxq.push(num);
        }
        else if (n % 2 == 0)
        {
            if (num <= maxq.top())
            {
                maxq.push(num);
            }
            else
            {
                minq.push(num);
                auto tmp = minq.top();
                minq.pop();
                maxq.push(tmp);
            }
        }
        else
        {
            if (num >= maxq.top())
            {
                minq.push(num);
            }
            else
            {
                maxq.push(num);
                auto tmp = maxq.top();
                maxq.pop();
                minq.push(tmp);
            }
        }
    }

    double findMedian()
    {
        int n = minq.size() + maxq.size();
        return n % 2 == 1 ? maxq.top() : (maxq.top() + minq.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */