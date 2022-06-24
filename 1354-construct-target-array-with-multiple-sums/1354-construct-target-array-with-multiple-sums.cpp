class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq(target.begin(), target.end());
        long total = accumulate(target.begin(), target.end(), (long)0);
        
        while (true) {
        int maximum = pq.top();
        pq.pop();
        total -= maximum;
        if (maximum == 1 || total == 1)
            return true;
        if (maximum < total || total == 0 || maximum % total == 0)
            return false;
        int next = maximum % total;
        total += next;
        pq.push(next);
        }
        
    }
};