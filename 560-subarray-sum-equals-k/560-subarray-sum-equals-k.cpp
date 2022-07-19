class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumsOccurenceMap;
        sumsOccurenceMap[0] = 1;

        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sumsOccurenceMap.find(sum - k) != sumsOccurenceMap.end()) {
                count += sumsOccurenceMap[sum - k];
            }
                sumsOccurenceMap[sum]++;
        }
        return count;
        
        
    }
};