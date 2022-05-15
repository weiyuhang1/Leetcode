class Solution {
    
    public:
  vector<string> findItinerary(vector<vector<string>> tickets) {
    hash.clear();
    num_airport = tickets.size() + 1;
    for (const auto& p : tickets) ++hash[p[0]][p[1]];

    path = {"JFK"};
    dfs("JFK");
    return path;
  }
  
private:
  bool dfs(string from) {
    if (path.size() == num_airport) return true;

    if (hash.find(from) == hash.end()) return false;
    map<string, int> to_list = hash[from];
    for (const auto& it : to_list) {
      if (it.second == 0) continue;
      
      string to = it.first;
      path.push_back(to);
      --hash[from][to];
      if (dfs(to)) return true;
      path.pop_back();
      ++hash[from][to];
    }
    return false;
  }
  
  unordered_map<string, map<string, int>> hash;
  int num_airport;
  vector<string> path;
    
/*
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            if (mp.find(ticket[0]) == mp.end()) {
                  mp[ticket[0]][ticket[1]]++;
            }
          
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
    for (auto target : mp[path.back()]) {
        if (target.second > 0) {
            path.push_back(target.first);
            target.second--;
            if (backtracking(ticketnum)) return true;
            path.pop_back();
            target.second++;
        }
    }
    return false;
    } */
    
};