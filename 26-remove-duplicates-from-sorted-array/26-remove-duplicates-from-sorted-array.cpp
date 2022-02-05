class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 0;
        int val = 200;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[slowIndex] = nums[i];
                slowIndex++;
                val = nums[i];
            }
        }
        return slowIndex;
        
    }
};