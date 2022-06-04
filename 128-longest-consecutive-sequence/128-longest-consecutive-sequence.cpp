class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        int longeststreak = 0;
        for (int num : nums) {
            int streak = 1;
            if (s.find(num - 1) == s.end()) {
                while (s.find(++num) != s.end()) {
                    streak++;
                }
                longeststreak = max(longeststreak, streak);
            }
        }
        return longeststreak;
    }
};