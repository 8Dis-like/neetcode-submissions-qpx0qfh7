class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]=true;
        int dir[5]={1,0,-1,0,1};
        while(!pq.empty()){
            auto cur=pq.top();pq.pop();
            int t=cur[0],r=cur[1],c=cur[2];
            if(r==n-1&&c==n-1)return t;
            for(int i=0;i<4;i++){
                int nx=r+dir[i],ny=c+dir[i+1];
                if(nx>=n||nx<0||ny>=n||ny<0||vis[nx][ny])continue;
                vis[nx][ny]=true;
                pq.push({max(t,grid[nx][ny]),nx,ny});
            }
        }return n*n;
    }
};
