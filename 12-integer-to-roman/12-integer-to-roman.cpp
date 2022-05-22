class Solution {
public:
    string intToRoman(int num) {
        string result;
        int thousand = num / 1000;
        for (int i = 0; i < thousand; i++)
            result.push_back('M');
        num = num % 1000;
        
        int hundrad = num / 100;
        for (int i = 0; i < hundrad; ) {
            if (hundrad == 4) {
                result += "CD";
                break;
            } else if (hundrad == 9) {
                result += "CM";
                break;
            } else if (hundrad > 4) {
                result += 'D';
                hundrad -= 5;
            } else {
                result += 'C';
                hundrad -= 1;
            }
        }
        num = num % 100;
        
        int ten = num / 10;
        for (int i = 0; i < ten; ) {
            if (ten == 4) {
                result += "XL";
                break;
            } else if (ten == 9) {
                result += "XC";
                break;
            } else if (ten > 4) {
                result += 'L';
                ten -= 5;
            } else {
                result += 'X';
                ten -= 1;
            }
        }
        num = num % 10;
        
        int one = num;
        for (int i = 0; i < one; ) {
            if (one == 4) {
                result += "IV";
                break;
            } else if (one == 9) {
                result += "IX";
                break;
            } else if (one > 4) {
                result += 'V';
                one -= 5;
            } else {
                result += 'I';
                one -= 1;
            }
        }
        return result;
    }
};