class Solution {
/*
    private:
    bool compare(vector<int> v1, vector<int> v2) {
        return v1.back() <= v2.back();
    }
*/
public:

    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].front() < intervals[i - 1].back())
                return false;
        }
        return true;
        
    }
};