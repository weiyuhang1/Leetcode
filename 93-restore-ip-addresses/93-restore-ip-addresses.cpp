class Solution {
public:
    
    vector<string> restoreIpAddresses(string s) {
            vector<string> ip;
        backtracking(s, 0, 4, ip, result);
        return result;
    }
private:
    vector<string> result;

    void backtracking(string& s, int startindex, int k, vector<string>& ip,  vector<string>& result) {
        if (k == 0) {
            if (startindex >= s.size()) {
                result.push_back(print(ip));
     
            }
                       return;
        }
        for (int i = 1; i <= 3 && startindex + i <= s.size(); i++) {
            string str = s.substr(startindex, i);
            if (validIP(str)) {
                ip.push_back(str);
                backtracking(s, i + startindex, k - 1, ip, result);
                ip.pop_back();
            } else {
                break;
            }
        }
    }
    string print(vector<string> ip) {
        string str;
        for (int i = 0; i < ip.size() - 1; i++) {
            str += ip[i] + ".";
        }
        str += ip.back();
        return str;
    }
    bool validIP(string& str) {
        if (str.size() == 0) return false;
        if (str.size() > 3) return false;
     //   if (str.length() > 1 && str[0] == 0) return false;
        int n = stoi(str);
   
        if (n < 0 || n > 255) return false;
        if (str.size() > 1 && str[0] == '0') return false;
        return true;
    }
    
    
    
};