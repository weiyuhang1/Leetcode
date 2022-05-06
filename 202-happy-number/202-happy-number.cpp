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
    int result = 0;
            while (n > 0) {
                result += pow((n % 10), 2);
                n /= 10;
            }
    return result;
} 
    
};