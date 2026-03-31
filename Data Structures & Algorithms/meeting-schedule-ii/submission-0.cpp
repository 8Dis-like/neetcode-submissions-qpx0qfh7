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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>s;vector<int>e;
        for(auto inter:intervals){s.push_back(inter.start);e.push_back(inter.end);}
        sort(s.begin(),s.end());sort(e.begin(),e.end());
        int rooms=0;int cnt=0;int j=0;
        for(int i=0;i<s.size();i++){
            while(s[i]>=e[j]){cnt--;j++;}
            cnt++;
            rooms=rooms>cnt?rooms:cnt;
        }
        return rooms;
    }
};
