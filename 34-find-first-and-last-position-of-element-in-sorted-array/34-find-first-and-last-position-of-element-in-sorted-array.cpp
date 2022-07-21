class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //lower_bound
        vector<int> :: iterator lo, hi;
        lo = lower_bound(nums.begin(), nums.end(), target);
        hi = upper_bound(nums.begin(), nums.end(), target);
        int loindex = (int)(lo - nums.begin());
        int hiindex = (int)(hi - nums.begin());
        if (lo == nums.end() || *lo != target) return {-1, -1};
        return {loindex, hiindex - 1};
    }
};