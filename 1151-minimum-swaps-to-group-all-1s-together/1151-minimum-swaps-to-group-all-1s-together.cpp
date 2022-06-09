class Solution {
public:
    int minSwaps(vector<int>& data) {
        int len = 0;
        for (int num : data) {
            if (num == 1)
                len++;
        }
        int count = 0;
        
        for (int i = 0; i < len; i++) {
            if (data[i] == 1) count++;
        }
        int maxcount = count;
        for (int i = 1; i + len - 1 < data.size(); i++) {
            int r = i + len - 1;
            count += data[r] - data[i - 1];
            maxcount = max(maxcount, count);
        }
        return len - maxcount;
    }
};