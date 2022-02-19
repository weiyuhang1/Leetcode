class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int result = 0;
        int sublength = 0;
        unordered_map<int, int> count;
        for (int i = 0, j = 0; j < fruits.size(); ++j) {
            count[fruits[j]]++;
            while (count.size() > 2) {
                count[fruits[i]]--;
                if  (count[fruits[i]] == 0)
                    count.erase(fruits[i]);
                i++;
            }
            result = max(result, j - i +1);
        }
        return result;
    }
};