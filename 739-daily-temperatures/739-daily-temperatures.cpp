class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<pair<int, int>> st;
        
        //  monotonic non increasing
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                answer[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return answer;
    }
};