class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;      
        
        if (nums.empty()) {
            range(lower, upper, result);
            return result;
        }
        
        
        if (lower == upper) return result;

        
        if (nums[0] > lower)
            range(lower, nums[0] - 1, result);
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] > 1)
                range(nums[i - 1] + 1, nums[i] - 1, result);         
        }
        
        if (nums.back() < upper)
            range(nums.back() + 1, upper, result);
        
        return result;
        
    }
private:
    void range(int a, int b, vector<string>& result) {
                if (a == b) {
                    result.push_back(to_string(a));
                } else {
                    result.push_back(to_string(a) + "->" + to_string(b));
                }
    }
    
};