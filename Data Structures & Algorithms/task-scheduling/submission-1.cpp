class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>cnt(26,0);
        for(auto t:tasks)cnt[t-'A']++;
        //maxheap for processing order
        priority_queue<int>maxHeap;
        for(auto f:cnt){
            if(f>0)maxHeap.push(f);
        }
        //queue for cooldown 
        queue<pair<int,int>>cool;
        int time=0;
        while(!maxHeap.empty()||!cool.empty()){
            time++;
            if(!maxHeap.empty()){
                auto f=maxHeap.top()-1;
                maxHeap.pop();
                if(f>0)cool.push({f,time+n});
            }
            if(maxHeap.empty()&&!cool.empty())time=cool.front().second;
            if(!cool.empty()&&time==cool.front().second){
                maxHeap.push(cool.front().first);
                cool.pop();
            }
        }
        return time;
    }
};
