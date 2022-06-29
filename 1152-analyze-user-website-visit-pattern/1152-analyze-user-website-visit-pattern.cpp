class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> dict;
        set<vector<string>> seqs;
        map<vector<string>, int> seqscount;
        
        
        for (int i = 0; i < username.size(); i++) {
            dict[username[i]].push_back({timestamp[i], website[i]});
        }
        for (auto& p : dict) {
            sort(p.second.begin(), p.second.end());
            seqs.clear();
            
            //generate all the possible non-repeated patterns of each user
            // each user can only contributes to seqcount once
            int n = p.second.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        seqs.insert({p.second[i].second, p.second[j].second, p.second[k].second});
                    }
                }
            }
            
            for (auto& seq : seqs) {
                seqscount[seq]++;
            }
        }
        
        return max_element(seqscount.begin(), seqscount.end(), comp)->first;
        
    }
private:
    static bool comp(pair<vector<string>, int> p1, pair<vector<string>, int> p2) {
        return p1.second == p2.second ? p1.first > p2.first : p1.second < p2.second;
    } 
    
};