class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int minlen = INT_MAX;
        for (int i = 0, j = 0; j < cards.size(); j++) {
            if (mp.find(cards[j]) == mp.end()) {
                mp[cards[j]] = j;
            } else {
                minlen = min(minlen, j - mp[cards[j]] + 1);
                mp[cards[j]] = j;
            }
        }
        return minlen == INT_MAX ? -1 : minlen;
    }
};