class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        int sum=0;
        vector<int>maxl(len,0);
        vector<int>maxr(len,0);
        int ml=0;
        for(int i=0;i<len;i++){
            maxl[i]=ml>height[i]?ml:height[i];
            ml=ml>height[i]?ml:height[i];
        }
        int mr=0;
        for(int i=len-1;i>=0;i--){
            maxr[i]=mr>height[i]?mr:height[i];
            mr=mr>height[i]?mr:height[i];
        }
        for(int i=0;i<len;i++){
            sum+=(min(maxl[i],maxr[i])-height[i]);
        }return sum;
    }
};
