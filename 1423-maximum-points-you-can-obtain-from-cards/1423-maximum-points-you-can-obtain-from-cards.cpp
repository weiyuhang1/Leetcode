class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        const int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int currentsum = accumulate(cardPoints.begin(), cardPoints.begin() + n - k, 0);
        int result = currentsum;
        for (int i = 0, j = n - k; j < n; i++, j++) {
            currentsum += (cardPoints[j] - cardPoints[i]);
            result = min(result, currentsum);
        }
        return sum - result;
    }
    

    
};