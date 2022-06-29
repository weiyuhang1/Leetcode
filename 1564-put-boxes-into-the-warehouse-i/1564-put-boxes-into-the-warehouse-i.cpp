class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        for (int i = 1; i < warehouse.size(); i++) {
            warehouse[i] = min(warehouse[i], warehouse[i - 1]);
        }
        int last = warehouse.size();
        int count = 0;
        for (int i = warehouse.size() - 1; i >= 0; i--) {
            if (count < boxes.size() && warehouse[i] >= boxes[count]) 
                count++;
        }
        
        return count;
    }
};