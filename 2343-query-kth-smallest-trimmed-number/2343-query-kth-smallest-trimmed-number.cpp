class Solution {
public:

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        int len = nums[0].length();
        vector<pair<string, int>> nums1;
        nums1.clear();
            
            for (int i = 0; i < nums.size(); i++) {
                nums1.push_back({nums[i], i});
            }
        for (auto query : queries) {
            int k = query[0];
            int trim = query[1];

            nth_element(nums1.begin(), nums1.begin() + k - 1, nums1.end(), [&](const auto& a, const auto& b) {
                int cmp = a.first.compare(len - trim, string :: npos, b.first, len - trim, string :: npos);
                if (cmp == 0) {
                    return a.second < b.second;
                } else {
                    return cmp < 0;
                }
            });
            result.push_back(nums1[k - 1].second);
       //     result.push_back(findKthSmallest(nums1, query[0], 0, nums1.size() - 1));
        }
        return result;
        
    }

    int partition(vector<string>& nums, int p, int r) {
        int q = p + rand() % (r - p + 1);
        swap(nums[q], nums[r]);
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (nums[j] < nums[r]) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int findKthSmallest(vector<string>& nums, int k, int l, int r) {
        if (l == r) return l;
        if (l > r) return -1;
        int pivot = partition(nums, l, r);
        int len = pivot - l + 1;
        if (pivot == k) {
            return pivot;
        } else if (pivot > k) {
            return findKthSmallest(nums, k, l, pivot - 1);
        } else {
            return findKthSmallest(nums, k, pivot + 1, r);
        }
    }
    
    
};