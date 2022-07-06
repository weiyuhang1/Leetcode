class Solution {
public:
    int minFlipsMonoIncr(string s) {
        const int n = s.length();
        int zeros = 0;

        for (char& c : s) {
            if (c == '0') {
                zeros++;
            }
        }
        
        vector dp(n + 1, 0);
        
        //left of 0 needs 0 conversions, right part should be all 1s so need number of zeros conversions
        dp[0] = zeros;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                dp[i + 1] = dp[i] - 1;
            } else {
                dp[i + 1] = dp[i] + 1;
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};