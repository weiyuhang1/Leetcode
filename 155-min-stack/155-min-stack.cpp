class MinStack {
public:
    stack<int> value;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int val) {
        value.push(val);
        min.empty() || val < min.top() ? min.push(val) : min.push(min.top());
    }
    
    void pop() {
        value.pop();
        min.pop();
    }
    
    int top() {
        return value.top();
    }
    
    int getMin() {
        return min.top();
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