class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int number_of_rows = triangle.size();
        vector<int> dp(number_of_rows + 1, 0);
        for (int i = 1; i <= number_of_rows; i++) {
            dp[i] = dp[i - 1] + triangle[i - 1].back();
            for (int j = i - 1; j >= 1; j--) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i - 1][j];
            }
            dp[0] += triangle[i - 1][0];
        }
        return *min_element(dp.begin(), dp.end());
    }
};