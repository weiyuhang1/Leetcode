class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = nums1.size() - 1; i >= n; i--)
            nums1[i] = nums1[i - n];
        int i = n;
        int j = 0;
        int k = 0;
        while (i < nums1.size() && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[k] = nums1[i];
                i++;
                k++;
            } else {
                nums1[k] = nums2[j];
                j++;
                k++;
            }
        }
            while (i < nums1.size())
                nums1[k++] = nums1[i++];
            while (j < nums2.size())
                nums1[k++] = nums2[j++];
    }
};