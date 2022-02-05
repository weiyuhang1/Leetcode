class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while (left <= right){
            long mid = left + (right - left) / 2;
            if (mid * mid > x)
                right = mid - 1;
            else if (mid * mid < x)
                left = mid + 1;
            else return mid; 
            
        }
        return right;
        
    }
};