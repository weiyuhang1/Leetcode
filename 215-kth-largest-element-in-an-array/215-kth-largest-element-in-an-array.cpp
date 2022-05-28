class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return KthSmallest(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
private:
    int KthSmallest(vector<int>& nums, int l, int r, int k) {
        if (k > 0 && k <= r - l + 1) {
            int n = r - l + 1;
            int i;
            vector<int> median((n + 4) / 5);
            for (i = 0; i < n / 5; i++)
                median[i] = findMedian(nums, l + i * 5, l + i * 5 + 4);
            if (i * 5 < n) {
                median[i] = findMedian(nums, l + i * 5, l + i * 5 + n % 5 - 1);
                i++;
            }
            int medofmed = (i == 1) ? median[0] : KthSmallest(median, 0, i - 1, i / 2);
            int pos = partition(nums, l, r, medofmed);
            
            if (pos - l == k - 1) {
                return nums[pos];
            } else if (pos - l > k - 1) {
                return KthSmallest(nums, l, pos - 1, k);
            } else {
                return KthSmallest(nums, pos + 1, r, k -pos + l -1);
            }
        }
        return INT_MAX;
        
    }
    int findMedian(vector<int>& nums, int l, int r) {
        sort(nums.begin() + l, nums.begin() + r + 1);
        return nums[l + (r - l) / 2]; 
    }
    
    int partition(vector<int>& nums, int l, int r, int x) {
        int i;
        for (i = l; i < r; i++) {  //left close right open
            if (nums[i] == x) break;
        } 
        swap(nums[i], nums[r]); //skip if x already at the r position
        
        //standard partition algorithm
        i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] <= x) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
        
        
    }
    
    
};