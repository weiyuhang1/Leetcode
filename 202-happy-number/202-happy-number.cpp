class Solution {
public:
    bool isHappy(int n) {
        int next = n;
        unordered_set<int> set;
        while (set.find(next) == set.end()) {
            set.insert(next);
            next = getNext(next);

            if (next == 1) return true;
        }
        return false;

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