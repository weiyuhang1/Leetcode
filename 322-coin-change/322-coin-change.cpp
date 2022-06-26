class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        queue<int> q;
        unordered_set<int> dp;
        for (int coin : coins) {
                q.push(coin);

            
        }
        int round = 1;
        int minimum = *min_element(coins.begin(), coins.end());

        while (!q.empty() && round <= amount/minimum + 1) {
            int  sz = q.size();
            while (sz--) {
                int val = q.front();
                q.pop();
              
                if (val == amount) return round;
                if (val > amount) continue;
                
                for (int coin : coins) {
                    if (coin <= amount - val && dp.find(coin + val) ==dp.end()) {
                        q.push(coin + val);
                        dp.insert(coin + val);
                    }
                }
                
            }
            round++;
        }
        return -1;
        
        
        
    }
};