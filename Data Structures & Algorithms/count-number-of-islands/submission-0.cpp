class Solution {
public:
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;  // 越界了，直接跳过
        if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') { // 没有访问过的 同时 是陆地的

            visited[nextx][nexty] = true;
            dfs(grid, visited, nextx, nexty);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();int cols=grid[0].size();
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        int num=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    dfs(grid,vis,i,j);
                    num++;
                }
            }
        }return num;
    }
};
