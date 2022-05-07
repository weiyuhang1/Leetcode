class MyQueue {
public:
    stack<int> s;
    stack<int> s2;
    MyQueue() {

        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s.empty()) {
                s2.push(s.top());
                s.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s.empty()) {
                s2.push(s.top());
                s.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s.empty() && s2.empty();
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