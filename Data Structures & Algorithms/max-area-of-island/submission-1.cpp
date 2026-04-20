class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int i,int j,int & cnt){
        vis[i][j]=true;
        cnt++;
        int m=grid.size();
        int n=grid[0].size();
        for(int k=0;k<4;k++){
            int nx=i+dir[k];
            int ny=j+dir[k+1];
            if(nx<0||ny<0||nx>=m||ny>=n||vis[nx][ny]||grid[nx][ny]==0)continue;
            dfs(grid,vis,nx,ny,cnt);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int area=0;
                if(grid[i][j]==1&&!vis[i][j])dfs(grid,vis,i,j,area);
                res=res>area?res:area;
            }
        }
        return res;
    }
};
