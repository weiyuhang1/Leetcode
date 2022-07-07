class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        vector<int> segment;
        int MaxLen = 0;
        for (int num : nums) {
            if (num == 0) { //TODO
                MaxLen = max(MaxLen, help(segment));
                segment.clear();
            } else {
                segment.push_back(num);
            }
            
        }
        MaxLen = max(MaxLen, help(segment));
        
        return MaxLen;
        
    }
private:
    //getMaxLen on array without zeros
    int help(vector<int>& segment) {
        int negative_amount = 0;
        int first_negative = -1;
        int last_negative = -1;
        for (int i = 0; i < segment.size(); i++) {
            if (segment[i] < 0) {
                negative_amount++;
                if (first_negative == -1) first_negative = i;
                last_negative = i;
            }
        }
        if (negative_amount % 2 == 0) {
            return segment.size();
        } else {
            return segment.size() - first_negative - 1 > last_negative ? segment.size() - first_negative - 1 : last_negative;
        }
    }
    
    
};