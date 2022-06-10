class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end()); //begin, end
       
        int k = INT_MAX;
        long totaltime;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            totaltime = 0;
            for (int pile : piles) {
                totaltime += ceil((double)pile / (double)mid);
            
            }
            if (totaltime > h) {
                lo = mid + 1;
            } else if (totaltime <= h) {
                k = min(k, mid);
                hi = mid - 1;
            } else {
             //   return mid;
            }
        }
        return k;
        
    }
};