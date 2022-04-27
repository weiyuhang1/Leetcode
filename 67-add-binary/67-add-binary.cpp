class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())
            return addBinary(b,a);
        int sum = 0;
        int j = 0;
        string result = "";
        int n = a.length();
        for (int i = n - 1; i >= 0; i--){
            if (j < b.size()){
                sum += b[b.size() - j - 1] - '0';
                j++;
            }
            sum += a[i] - '0';
            result += sum % 2 + '0';
               


            sum = sum / 2;
        }
        reverse(result.begin(), result.end());
        if (sum == 1) result = "1" + result;
        return result;
    }
};