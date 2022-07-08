class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> umap;
        vector<int> answer(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                umap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (umap.find(nums1[i]) != umap.end()) {
                answer[i] = umap[nums1[i]];
            }
        }
        return answer;
    }
};