class Solution {
public:
    int jump(vector<int>& nums) {
        int curcover = 0;
        int nextcover = 0;
        int step = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (curcover >= nums.size() - 1) return step;
            nextcover = max(nextcover, i + nums[i]);
            if (curcover == i) {
                step++;
                curcover = nextcover;
            }
          
        }
        return INT_MAX;
    }
};