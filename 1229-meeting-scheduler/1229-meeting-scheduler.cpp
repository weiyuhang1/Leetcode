class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), comp);
        sort(slots2.begin(), slots2.end(), comp);

        return helper(slots1, slots2, duration);
   //     
        
    }
    static bool comp(vector<int>& vect1, vector<int>& vect2) {
        return vect1[0] < vect2[0];
    }
private:
    vector<int> helper(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        vector<int> result;
        const int m = slots1.size();
        const int n = slots2.size();
        for (int i = 0, j = 0; i < m && j < n; ) {
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if (end - start >= duration) return {start, start + duration};
            if (slots1[i][1] < slots2[j][1]) {
                i++;
            } else {
                j++;
            }
            
            
        }
        return {};
    }
    
    
    
};