class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        queue<int> q;
        vector<bool> dp(amount + 1, true);
        for (const int& coin : coins) {
                q.push(coin);

            
        }
        int round = 1;

        while (!q.empty()) {
            int  sz = q.size();
            while (sz--) {
                int val = q.front();
                q.pop();
              
                if (val == amount) return round;
                
                for (int coin : coins) {
                    if (coin <= amount - val && dp[coin + val] == true) {
                        q.push(coin + val);
                        dp[coin + val] = false;
                    }
                }
                
            }
            round++;
        }
        return -1;
        
        
        
    }
};