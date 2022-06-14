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
            mp[nums[j]]++;
            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
                
            }
            
            
                    times += j - i + 1;
    
        }
        return times;
        
    }
    
    
    
};