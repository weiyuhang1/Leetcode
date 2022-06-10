class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int left = 0;
        int right = matrix.size() * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int pivot = matrix[mid / n][mid % n];
            if (pivot > target) {
                right = mid - 1;
            } else if (pivot < target){
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};