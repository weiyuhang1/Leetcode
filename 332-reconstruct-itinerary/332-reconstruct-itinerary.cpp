class Solution {


public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
                  mp[ticket[0]][ticket[1]]++;

        }
        path.push_back("JFK");
        backtracking(tickets.size());
        return path;
        
    }
private:
    unordered_map<string, map<string, int>> mp;
    vector<string> path;
    bool backtracking(int ticketnum) {
        if (path.size() ==ticketnum + 1) return true;
    if (mp.find(path.back()) == mp.end()) return false;
    for (auto& target : mp[path.back()]) {
        if (target.second > 0) {
            path.push_back(target.first);
            target.second--;
            if (backtracking(ticketnum)) return true;
            path.pop_back();
            target.second++;
        }
    }
    return false;
    } 

};