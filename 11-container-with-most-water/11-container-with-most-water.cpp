class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int area = min(height[r], height[l]) * (r - l);

        while (l < r - 1) {
            area = max(area, nextArea(height, l, r));  
            }
        return area;
    }
private:
    int nextArea(vector<int>& height, int& l, int& r) {
        int area = 0;
                int h = 0;
           if (height[l] < height[r]) {
                h = height[l];
                do {
                    l++;
                }
                while (l + 1 < r && height[l] <= h);
            } else {
                h = height[r];
                do {
                    r--;
                } while (r - 1 > l && height[r] <= h);
            }
         area = min(height[r], height[l]) * (r - l);
        return area;
    }
};