class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int row=heights.size();int cols=heights[0].size();
      vector<vector<bool>>visp(row,vector<bool>(cols,false));
      vector<vector<bool>>visa(row,vector<bool>(cols,false));
      for(int i=0;i<row;i++)dfs(heights,visp,i,0);
      for(int j=0;j<cols;j++)dfs(heights,visp,0,j);
      for(int i=0;i<row;i++)dfs(heights,visa,i,cols-1);
      for(int j=0;j<cols;j++)dfs(heights,visa,row-1,j);
      vector<vector<int>>res;
      for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
            if(visp[i][j]&&visa[i][j])res.push_back(vector<int>{i,j});
        }
      }return res;
    }
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
void dfs(vector<vector<int>>& heights,vector<vector<bool>>&vis,int x,int y){
        vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) continue;  
        if (!vis[nextx][nexty] && heights[x][y]<=heights[nextx][nexty])dfs(heights, vis, nextx, nexty);
    }return;
    }
};
