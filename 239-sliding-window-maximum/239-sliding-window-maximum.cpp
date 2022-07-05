class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            while (!dq.empty() && dq.back() < nums[j]) dq.pop_back();
            dq.push_back(nums[j]);
            if (j >= k - 1) {
                result.push_back(dq.front());
                if (dq.front() == nums[j - k + 1]) dq.pop_front();
            }
        }
        return result;
    }
};