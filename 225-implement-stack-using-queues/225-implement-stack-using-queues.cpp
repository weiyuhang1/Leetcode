class MyStack {
public:
    queue<int> q;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        
    }
    
    int pop() {
        while (q.size() > 1) {
            int top = q.front();
            q2.push(top);
            q.pop();
        }
        int top = q.front();
        q.pop();
        swap(q,q2);
        return top;

    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */