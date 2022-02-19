// Two solution
class MinStack {
public:
    stack<long> s;
    long min_value;
    MinStack() {
        // min_value = INT_MAX;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            min_value = val;
        }
        else if(val >= min_value)
            s.push(val);
        else{
            s.push(2 * long(val) - min_value);
            min_value = val;
        }
    }
    
    void pop() {
        if(s.top() >= min_value){
            s.pop();
        }
        else{
            min_value = 2 * min_value -  s.top();
            s.pop();
        }
    }
    
    int top() {
        return s.top() >= min_value ? s.top() : min_value;
    }
    
    int getMin() {
        return min_value;
    }
};

class MinStack {
public:
    stack<int> s;
    stack<int> ms;
    MinStack() {
        ms.push(INT_MAX);
    }
    
    void push(int val) {
        s.push(val);
        ms.push(min(ms.top(), val));
    }
    
    void pop() {
        s.pop();
        ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */