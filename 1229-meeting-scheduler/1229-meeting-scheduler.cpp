class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), comp);
        sort(slots2.begin(), slots2.end(), comp);

        vector<int> result1 = helper(slots1, slots2, duration);
        vector<int> result2;
        result2 = helper(slots2, slots1, duration);
        if (result1.empty()) return result2;
        if (result2.empty()) return result1;
        return result1[0] < result2[0] ? result1 : result2;
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
            while (slots1[i][0] > slots2[j][0]) {
                j++;
                if (j >= n) return {};
            }
            if (slots2[j][0] + duration <= slots2[j][1] && slots2[j][0] + duration <= slots1[i][1]) {
                return {slots2[j][0], slots2[j][0] + duration};
            } else {
                if (j + 1 < n && slots2[j + 1][0] < slots1[i][1]) {
                    j++;
                } else {
                    
                    i++;
                }
                
            }
        }
        return {};
    }
    
    
    
};