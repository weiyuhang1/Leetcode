class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    //    return subarraysWithAtMostKDistinct(nums, k - 1);
    }
private:
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
         unordered_map<int, int> mp;
        int times = 0;
           
                int startnum;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            if (mp.size() < k || mp.find(nums[j]) != mp.end()) {
                mp[nums[j]] = j;
            } else {
                mp[nums[j]] = j;
                          int startindex = INT_MAX;
                for (const pair<int, int>& pair : mp) {
                    if (pair.second  < startindex) {
                        startnum = pair.first;
                        startindex = pair.second;
                    }
                    
                }
        
                mp.erase(startnum);
                i = startindex + 1;
                
      
            }
                    times += j - i + 1;
    
        }
        return times;
        
    }
    
    
    
};