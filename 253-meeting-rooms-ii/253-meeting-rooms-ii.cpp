class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int d = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (vector<int>& interval : intervals) {
            if (pq.empty() || pq.top() > interval[0]) {
                d++;
                pq.push(interval[1]);
            } else {
                int earliestfinish = pq.top();
                pq.pop();
                pq.push(interval[1]);
            }
        }
        return d;
    }
};