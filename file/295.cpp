class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int, vector<int>, less<int>> q2;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int n = q1.size() + q2.size();
        if(n == 0)
            q1.push(num);
        else if(n % 2 == 0){
            if(num <= q2.top()){
                q2.push(num);
                q1.push(q2.top());
                q2.pop();
            }
            else
                q1.push(num);
        }
        else{
            if(num <= q1.top())
                q2.push(num);
            else{
                q1.push(num);
                q2.push(q1.top());
                q1.pop();
            }
        }
    }
    
    double findMedian() {
        int n = q1.size() + q2.size();
        return n % 2 == 0 ? (q1.top() + q2.top()) / 2.0 : q1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */