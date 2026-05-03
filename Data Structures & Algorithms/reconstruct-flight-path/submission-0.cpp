class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for(auto &tic:tickets)adj[tic[0]];
        sort(tickets.begin(),tickets.end());
        for(auto &tik:tickets)adj[tik[0]].push_back(tik[1]);
        vector<string>res={"JFK"};
        dfs(adj,"JFK",res,tickets.size()+1);
        return res;
    }
private:
    bool dfs(unordered_map<string,vector<string>>&adj,const string &src,vector<string>&res,int size){
        if(res.size()==size)return true;
        if(adj.find(src)==adj.end())return false;
        vector<string>tmp=adj[src];
        for(int i=0;i<tmp.size();i++){
            string v=tmp[i];
            adj[src].erase(adj[src].begin()+i);
            res.push_back(v);
            if(dfs(adj,v,res,size))return true;
            adj[src].insert(adj[src].begin()+i,v);
            res.pop_back();
        }return false;
    }
};
