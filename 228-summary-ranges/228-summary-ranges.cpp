class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if (nums.empty()) return ranges;
        int r = nums[0];
        int l = r;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == r + 1) {
                r++;
            } else {
                addRange(l, r, ranges);
                l = nums[i];
                r = nums[i];
            }
        }
        addRange(l, r, ranges);
        return ranges;
    }
private:
    void addRange(int l, int r, vector<string>& ranges) {
        if (l == r) {
            ranges.push_back(to_string(l));
        } else {
            ranges.push_back(to_string(l) + "->" + to_string(r));
        }
    }
    
};