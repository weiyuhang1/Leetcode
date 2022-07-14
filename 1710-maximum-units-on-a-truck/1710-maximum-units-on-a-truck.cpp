class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int sum = 0;
        int i = 0;
        while (i < boxTypes.size()) {
            while (boxTypes[i][0] && truckSize) {
                 sum += boxTypes[i][1];
                 truckSize--;
                 boxTypes[i][0]--;
            }
              
            i++;
           
        }
        return sum;
    }
    static bool comp(vector<int>& boxType1, vector<int>& boxType2) {
        return boxType1[1] > boxType2[1];
    }
};