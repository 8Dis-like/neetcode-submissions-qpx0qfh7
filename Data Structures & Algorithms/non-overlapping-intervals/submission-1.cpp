class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1)return 0;    
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){return a[0]<b[0];});
        int res=0;
        int prevend=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prevend){
                res++;
                prevend=min(prevend,intervals[i][1]);
            }else prevend=intervals[i][1];
        }
        return res;
    }
};
