class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>cnt(26,0);
        for(char task:tasks)cnt[task-'A']++;

        priority_queue<int>pq;
        for(int ct:cnt){
            if(ct>0)pq.push(ct);
        }
        int time=0;
        queue<pair<int,int>>q;
        while(!pq.empty()||!q.empty()){
            time++;
            if(pq.empty())
                time=q.front().second;
            else{
                int ct=pq.top()-1;
                pq.pop();
                if(ct>0)q.push({ct,time+n});
            }
            if(!q.empty()&&q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }return time;
    }
};
