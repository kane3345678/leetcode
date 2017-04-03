Container With Most Water
https://leetcode.com/problems/container-with-most-water/#/description

class Solution {
public:
      int maxArea(vector<int>& height) {
        int max = 0;
        int i = 0, h = 0;
        int j  = height.size() - 1;
        int area = 0;
        while (i != j){
            int w = j - i;
            if (height[i] < height[j]) {
                h = height[i];
                i++;
            } else {
                h= height[j];
                j--;
            }
            max = (w*h > max )? w*h:max;
        }
        return max;
    }
};
