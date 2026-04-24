class UnionFind{
private:
    vector<int>par;
public:
    UnionFind(int n){
        par.resize(n+1);
        for(int i=0;i<=n;i++)par[i]=i;
    }
    int find(int u){
        return u==par[u]?u:par[u]=find(par[u]);
    }
    bool issame(int u,int v){
        u=find(u);
        v=find(v);
        return u==v;
    }
    void join(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v)return;
        else par[u]=v;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        UnionFind uf(n);
        for(auto nei:edges){
            if(uf.issame(nei[0],nei[1]))return nei;
            else uf.join(nei[0],nei[1]);
        }
    }
};
