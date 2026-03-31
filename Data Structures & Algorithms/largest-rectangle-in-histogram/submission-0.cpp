class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();
        vector<int>lb(size);
        vector<int>rb(size);
        lb[0]=-1;
        for(int i=1;i<size;i++){
            int t=i-1;
            while(t>=0&&heights[i]<=heights[t])t=lb[t];
            lb[i]=t;
        }
        rb[size-1]=size;
        for(int i=size-2;i>=0;i--){
            int t=i+1;
            while(t<size&&heights[i]<=heights[t])t=rb[t];
            rb[i]=t;
        }
        int sum=0;
        for(int i=0;i<size;i++){
            int area=heights[i]*(rb[i]-lb[i]-1);
            sum=sum>area?sum:area;
        }return sum;
    }
};
