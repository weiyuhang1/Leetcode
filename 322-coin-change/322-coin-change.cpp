class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        queue<int> q;
        unordered_set<int> dp;
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
                    if (coin <= amount - val && dp.find(coin + val) == dp.end()) {
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