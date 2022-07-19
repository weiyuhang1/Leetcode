class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        vector<pair<string, int>> nums1;
        for (int i = 0; i < nums.size(); i++) 
            nums1.push_back({nums[i], i});
        for (auto query : queries) {
            int k = query[0];
            int trim = query[1];
            findKthSmallest(nums1, k - 1, 0, nums1.size() - 1, trim);
            result.push_back(nums1[k - 1].second);
        }
        return result;    
    }

    int findKthSmallest(vector<pair<string, int>>& nums, int k, int l, int r, int trim) {
        if (l == r) return l;
        int pivot = partition(nums, l, r, trim);
        if (pivot == k) {
            return pivot;
        } else if (pivot > k) {
            return findKthSmallest(nums, k, l, pivot - 1, trim);
        } else {
            return findKthSmallest(nums, k, pivot + 1, r, trim);
        }
    }
    int partition(vector<pair<string, int>>& nums, int p, int r, int trim) {
        int q = p + rand() % (r - p + 1);
        swap(nums[q], nums[r]);
        int i = p - 1;
        for (int j = p; j < r; j++) {
            int cmp = nums[j].first.compare(
                nums[j].first.length() - trim, string :: npos, 
                nums[r].first, nums[r].first.length() - trim, string :: npos);
            if ((cmp == 0 && nums[j].second < nums[r].second) || cmp < 0) {
                i++;
                swap(nums[j], nums[i]);
            }
        }
        i++;
        swap(nums[i], nums[r]);
        return i;
    }
    
    
    
};