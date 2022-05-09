class Solution {
private:
    int SumOfDigits(int num) {
        int sum = 0;
        while (num / 10 > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum + num;
    }
public:
    int addDigits(int num) {
        while (num > 9) {
            num = SumOfDigits(num);
        }
        return num;
        
    }
};