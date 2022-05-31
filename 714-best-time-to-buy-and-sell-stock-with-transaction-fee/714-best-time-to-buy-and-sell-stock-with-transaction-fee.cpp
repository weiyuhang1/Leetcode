class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = prices[0];
        int sell = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] >= sell) {
                sell = prices[i];
            } else if (prices[i] < sell - fee) {
                if (sell - buy - fee > 0)
                    profit += sell - buy - fee;
                buy = prices[i];
                sell = prices[i];
            } else if (prices[i] < buy){
                buy = prices[i];
                sell = prices[i];
            }
        }
        if (sell - buy - fee > 0) profit += sell - buy - fee;
        return profit;
    }
};