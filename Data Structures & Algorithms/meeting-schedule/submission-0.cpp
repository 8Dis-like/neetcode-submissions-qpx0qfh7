/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0)return true;
        sort(intervals.begin(),intervals.end(),[](const Interval&a,const Interval&b){return a.start<b.start;});
        int prevend=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<prevend)return false;
            else prevend=intervals[i].end;
        }return true;
    }
};
