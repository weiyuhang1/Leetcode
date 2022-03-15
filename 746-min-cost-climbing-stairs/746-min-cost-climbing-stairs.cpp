class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int C[cost.size() + 1];
        C[0] = 0;
        C[1] = 0;
        for (int i = 2; i <= cost.size(); i++){
            C[i] = min(C[i - 1] + cost[i - 1], C[i - 2] + cost[i - 2]);
        }
        return C[cost.size()];
    }
};