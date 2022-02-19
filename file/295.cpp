// two solutions
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> min_q;
    priority_queue<int, vector<int>, less<int>> max_q;
    int size; //max_q.size() + min_q.size()

    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size == 0){
            min_q.push(num);
        }
        else if(size % 2 == 0){
            if(num >= min_q.top()){
                min_q.push(num);
            }
            else{
                max_q.push(num);
                int tmp = max_q.top();
                max_q.pop();
                min_q.push(tmp);
            }
        }
        else{
            if(num >= min_q.top()){
                min_q.push(num);
                int tmp = min_q.top();
                min_q.pop();
                max_q.push(tmp);
            }
            else{
                max_q.push(num);
            }
        }
        size++;
    }
    
    double findMedian() {
        return size % 2 == 0 ? (min_q.top() / 2.0 + max_q.top() / 2.0) : min_q.top();
    }
};

class MedianFinder {
public:
    multiset<int> s;
    multiset<int>::iterator l, r;

    MedianFinder() {
    }
    
    void addNum(int num) {
        s.insert(num);
        if(s.size() == 1){
            l = r = s.begin();
        }
        else if (s.size() & 1){
            if(num < *r && num >= *l){
                l++; r--;
            }
            else if(num >= *r){
                l++;
            }
            else{
                r--;
            }
        }
        else{
            if(num < *l)
                l--;
            else    
                r++;
        }
    }
    
    double findMedian() {
        // cout << *l << " " << *r << endl;
        return (*l / 2.0 + *r / 2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */