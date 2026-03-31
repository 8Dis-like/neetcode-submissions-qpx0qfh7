class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
    if(edges.size()>n-1)return false;
    vector<vector<int>>ndtb(n);
    for(auto &edge:edges){
        ndtb[edge[0]].push_back(edge[1]);
        ndtb[edge[1]].push_back(edge[0]);
    }
    unordered_set<int>vis;
    if(!dfs(0,-1,vis,ndtb))return false;
    return vis.size()==n;
    }
    bool dfs(int nd,int parent,unordered_set<int>& vis,vector<vector<int>>&ndtb){
        if(vis.count(nd))return false;
        vis.insert(nd);
        for(auto nei:ndtb[nd]){
            if(nei==parent)continue;
            if(!dfs(nei,nd,vis,ndtb))return false;
        }return true;
    }
};
