class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxArea = 0;

        while(i < j){
            int h = min(heights[i], heights[j]);
            int area = h * (j - i);

            if (area > maxArea){
                maxArea = area;
            } 

            if (heights[i] < heights[j]){
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};
