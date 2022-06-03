class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int max_freq = 1;
        for (const int& num : nums) {
            count[num]++;
            max_freq = max(max_freq, count[num]);
        }
        
        unordered_map<int, vector<int>> buckets;
        for (pair<int, int> p : count) {
            buckets[p.second].push_back(p.first);
        }
        vector<int> result;
        for (int i = max_freq; i >= 1; i--) {
            auto it = buckets.find(i);
            if (it == buckets.end()) continue;
            for (auto e : it->second) {
                result.push_back(e);
            }
            if (result.size() == k) return result;
        
        }
        return result;
        
    }
};