class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int area = min(height[r], height[l]) * (r - l);
        while (l < r - 1) {
            if (height[l] < height[r]) {
                int h = height[l];
                do {
                    l++;
                }
                while (l + 1 < r && height[l] <= h);
            } else {
                r--;
            }
            area = max(area, min(height[r], height[l]) * (r - l));
                
                
                
            }
        return area;
    }
private:
    int nextArea(vector<int>& height, int& l, int& r) {
        int area = 0;
           if (height[l] < height[r]) {
               l++;
                while (l < r && height[l + 1] <= height[l])
                    l++;
            } else {
               r--;
                while (r > l && height[r - 1] <= height[r])
                    r--;    
            }
         area = min(height[r], height[l]) * (r - l);
        return area;
    }
};