class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int arrow = 1;
        int finishtime = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > finishtime) {
                arrow++;
                finishtime = points[i][1];
            }
        }
        return arrow;
        
        
    }
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
        
    
};