class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lo.empty()) {
            lo.push(num);
            return;
        }
        if (num > lo.top()) {
            hi.push(num);
        } else {
            lo.push(num);
        }

        if (lo.size() > hi.size() + 1) {
            hi.push(lo.top());
            lo.pop();
        } else if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return (lo.size() == hi.size()) ? lo.top() + (double)(hi.top() - lo.top()) * 0.5 : (double)lo.top();
    }
private:
    priority_queue <int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */