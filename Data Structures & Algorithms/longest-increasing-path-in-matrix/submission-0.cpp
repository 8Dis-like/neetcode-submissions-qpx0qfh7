class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    vector<vector<int>>dp;

    int dfs(vector<vector<int>>& matrix,int r,int c,int prev){
        int m=matrix.size();
        int n=matrix[0].size();
        if(r>=m||c>=n||r<0||c<0||matrix[r][c]<=prev)return 0;
        if(dp[r][c]!=-1)return dp[r][c];
    
        int res=1;
        for(int k=0;k<4;k++){
            int nx=r+dir[k];
            int ny=c+dir[k+1];
            res=max(res,1+dfs(matrix,nx,ny,matrix[r][c]));
        }
        dp[r][c]=res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        int len=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                len=max(len,dfs(matrix,i,j,INT_MIN));
            }
        }return len;
    }
};
