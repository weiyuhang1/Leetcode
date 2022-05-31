class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1];
        int count = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
private:
    static bool cmp(vector<int>&a, vector<int>& b) {
        return a[1] < b[1];
    }

};