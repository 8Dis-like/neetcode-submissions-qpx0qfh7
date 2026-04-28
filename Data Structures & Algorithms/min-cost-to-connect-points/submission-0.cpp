class DSU{
public:
    vector<int>par,size;
    DSU(int n):par(n+1),size(n+1,1){
        for(int i=0;i<=n;i++)par[i]=i;
    }

    int find(int u){
        if(par[u]!=u){
            par[u]=find(par[u]);
        }return par[u];
    }

    bool join(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v)return false;
        else{
            if(size[u]<size[v])swap(u,v);
            size[u]+=size[v];
            par[v]=u;
            return true;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU dsu(n);
        vector<array<int,3>>edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int res=0;
        for(auto [dist,u,v]:edges){
            if(dsu.join(u,v))res+=dist;
        }return res;
    }
};
