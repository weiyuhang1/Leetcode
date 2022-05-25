class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] <= prices[i - 1]) {
                if (sell > buy) {
                    profit += sell - buy;
                    sell = 0;
                }
                buy = prices[i];             
            } else {
                sell = prices[i];
            }
        }
        if (sell - buy > 0) profit += sell - buy;
        return profit;
        
    }
};