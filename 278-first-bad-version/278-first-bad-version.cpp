// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        if (isBadVersion(l)) return l;
        int r = n;
        int mid;
        while (l < r - 1) {
            mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
        
        
    }
};