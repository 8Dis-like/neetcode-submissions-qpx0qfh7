class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = intervals.size();
        
        // Phase 1: Skip (and add) all intervals that end completely BEFORE the new interval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        
        // Phase 2: Merge all overlapping intervals into one giant newInterval
        // An overlap exists as long as the current interval starts before the new interval ends
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Push the successfully merged interval
        res.push_back(newInterval); 
        
        // Phase 3: Add all the remaining intervals that start completely AFTER the new interval ends
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};