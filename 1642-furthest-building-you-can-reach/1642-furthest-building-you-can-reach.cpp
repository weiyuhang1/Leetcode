class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        int i;
        for (i = 1; i < heights.size(); i++) {
            int gap = max(0, heights[i] - heights[i - 1]);
            pq.push(gap);
            if (pq.size() > ladders) {
                sum += pq.top();
                pq.pop();
            }
            if (sum > bricks) break;
        }
        return i - 1;
    }
};