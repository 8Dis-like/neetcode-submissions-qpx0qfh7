class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int maxarea=0;
        while(i<j){
            int area=(j-i)*min(heights[i],heights[j]);
            maxarea=area>maxarea?area:maxarea;
            if(heights[i]<=heights[j])i++;
            else j--;
        }return maxarea;
    }
};
