class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back() += 1;
        for (int i = digits.size()-1; i>=0; i--){
            if (digits[i] >= 10){
                digits[i] %= 10;
                if (i-1 >= 0){
                    digits[i-1] += 1;
                }else
                    digits.insert(digits.begin(),1);
                }
            
            }
        return digits;
    }
};