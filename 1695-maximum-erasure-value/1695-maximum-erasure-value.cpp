class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map <int, int> mp;
        int score = 0;
        int maxscore = INT_MIN;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            score += nums[j];
            if (mp.find(nums[j]) == mp.end() || mp[nums[j]] < i) {
                maxscore = max(score, maxscore);
                mp[nums[j]] = j;
            //    continue;
            } else {
                while (i <= mp[nums[j]]) {
                    score -= nums[i];
                    i++;
                }
                mp[nums[j]] = j;
            }
        }
        return maxscore;
    }
};