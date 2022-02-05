class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                nums[slowIndex] = nums[i];
                slowIndex++;
            }
        }
        return slowIndex;
        
    }
};