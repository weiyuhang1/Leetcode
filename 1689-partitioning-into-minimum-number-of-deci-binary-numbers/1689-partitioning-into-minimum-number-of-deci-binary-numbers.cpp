class Solution {
public:
    int minPartitions(string n) {
        int maximum = 0;
        for (char c : n) {
            maximum = max(maximum, c - '0');
        }
        return maximum;
    }
};