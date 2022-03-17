class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        int i,j;
       for (i=0;i<nums.size()-1;i++){
           for (j=i+1;j<nums.size();j++){
               if (nums[i]+nums[j]==target){
                   vec.push_back(i);
                   vec.push_back(j);
                  
               }
           }
       }   return vec;
    }
  
};