class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(fast);
             fast = getNext(fast);
        }
        

        return fast == 1;

    }
private:
    int getNext(int n) {
    int square_sum = 0;
            while (n > 0) {
                square_sum += pow((n % 10), 2);
                n /= 10;
            }
    return square_sum;
} 
    
};