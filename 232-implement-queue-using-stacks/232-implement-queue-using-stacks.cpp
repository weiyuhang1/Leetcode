class MyQueue {
public:
    stack<int> s;
    stack<int> s2;
    MyQueue() {
        s = {};
        s2 = {};
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while (s.size() > 1) {
            s2.push(s.top());
            s.pop();
        }
        int top = s.top();
        s.pop();
        while (!s2.empty()) {
            s.push(s2.top());
            s2.pop();
        }
        return top;
    }
    
    int peek() {
        while (s.size() > 1) {
            s2.push(s.top());
            s.pop();
        }
        int top = s.top();
        while (!s2.empty()) {
            s.push(s2.top());
            s2.pop();
        }

        return top;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */