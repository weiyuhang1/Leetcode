class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //lower_bound
        if (nums.empty()) return {-1, -1};
        vector<int> :: iterator lo, hi;
 //       lo = lower_bound(nums.begin(), nums.end(), target);
        hi = upper_bound(nums.begin(), nums.end(), target);
        int loindex = lower_bound(nums, target, 0, nums.size() - 1);
        int hiindex = hi - nums.begin();
 //       if (lo == nums.end() || *lo != target) return {-1, -1};
        if (loindex == -1) return {-1, -1};
        return {loindex, hiindex - 1};
    }
    int lower_bound(vector<int>& nums, int target, int l, int r) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
    
    
};