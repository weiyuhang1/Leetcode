class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int n = nums.size();
        vector<int> answer(n, -1);
        stack<int> st;
        //elements in nums are not guaranteed to be unique, use index instead of value
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                answer[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                answer[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};