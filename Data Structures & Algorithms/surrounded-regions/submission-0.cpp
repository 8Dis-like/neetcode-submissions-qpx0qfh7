class Solution {
public:
    int dir[5]={1,0,-1,0,1};
    void dfs(vector<vector<char>>& board,int x,int y){
        if(board[x][y]=='X'||board[x][y]=='#')return;
        board[x][y]='#';
        for(int i=0;i<4;i++){
            int nx=x+dir[i];
            int ny=y+dir[i+1];
            if(nx<0||nx>=board.size()||ny<0||ny>=board[0].size()||board[nx][ny] != 'O')continue;
            dfs(board,nx,ny);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')dfs(board,i,0);
            if(board[i][n-1]=='O')dfs(board,i,n-1);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O')dfs(board,0,j);
            if(board[m-1][j]=='O')dfs(board,m-1,j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='#')board[i][j]='O';
            }
        }
    }
};
