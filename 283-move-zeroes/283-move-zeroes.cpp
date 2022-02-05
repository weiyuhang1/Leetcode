class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] !=0){
                nums[slowIndex] = nums[i];
                slowIndex++;
            }
        }
        for (int i = slowIndex; i < nums.size(); i++){
            nums [i] = 0;
        }
        
    }
};