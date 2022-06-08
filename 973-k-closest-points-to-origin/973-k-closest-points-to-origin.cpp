
class Solution {     
    public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        for (vector<int> point : points) {
            pq.push(point);
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
private:
    struct comp{
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };
    
};
 
