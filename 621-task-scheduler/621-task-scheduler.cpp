class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for (char c : tasks) {
            mp[c - 'A']++;
        }
        int most = *max_element(begin(mp), end(mp));
        int nmax = count(begin(mp), end(mp), most);
        return max((most - 1) * (n + 1) + nmax, (int)tasks.size());
    }
};