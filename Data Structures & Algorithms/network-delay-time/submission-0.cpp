class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        for(int k=0;k<n-1;k++){
            for(auto time:times){
                int u=time[0]-1;
                int v=time[1]-1;
                int w=time[2];
                if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
                    dist[v]=dist[u]+w;
            }
        }
        int res=*max_element(dist.begin(),dist.end());
        return res==INT_MAX?-1:res;
    }
};
