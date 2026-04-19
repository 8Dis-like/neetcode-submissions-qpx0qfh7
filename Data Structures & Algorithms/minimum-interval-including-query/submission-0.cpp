class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<vector<int>>events;
        for(int i=0;i<intervals.size();i++){
            events.push_back({intervals[i][0],0,intervals[i][1]-intervals[i][0]+1,i});
            events.push_back({intervals[i][1],2,intervals[i][1]-intervals[i][0]+1,i});
        }

        for(int i=0;i<queries.size();i++)events.push_back({queries[i],1,i});
        sort(events.begin(),events.end(),[](const vector<int>&a,const vector<int>&b){return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];});
        vector<int>ans(queries.size(),-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>inactive(intervals.size(),false);

        for(const auto&e:events){
            if(e[1]==0)pq.push({e[2],e[3]});
            else if(e[1]==2)inactive[e[3]]=true;
            else {
                int q=e[2];
                while(!pq.empty()&&inactive[pq.top().second])pq.pop();
                if(!pq.empty())ans[q]=pq.top().first;
            }
        }return ans;
    }
};
