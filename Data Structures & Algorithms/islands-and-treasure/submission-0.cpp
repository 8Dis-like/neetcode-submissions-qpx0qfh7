class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    const int INF=2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=true;}
            }
        }
        int dis=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto [r,c]=q.front();q.pop();
                for(int j=0;j<4;j++){
                    int nx=r+dir[j];
                    int ny=c+dir[j+1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == INF){
                        grid[nx][ny]=dis;
                        q.push({nx,ny});
                    }
                }
            }dis++;
        }
    }
};
