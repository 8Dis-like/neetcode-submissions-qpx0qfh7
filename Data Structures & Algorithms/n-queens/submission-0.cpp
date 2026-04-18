class Solution {
public:
    vector<vector<string>>res;

    void backtracking(int n,vector<string> &chessboard,int row){
        if(row==n){
            res.push_back(chessboard);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(chessboard,i,row)){
                chessboard[row][i]='Q';
                backtracking(n,chessboard,row+1);
                chessboard[row][i]='.';
            }
        }
    }

    bool isValid(vector<string>chessboard,int col,int row){
        for(int i=0;i<row;i++)
            if(chessboard[i][col]=='Q')return false;
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
            if(chessboard[i][j]=='Q')return false;
        for(int i=row-1,j=col+1;i>=0&&j<chessboard[0].size();i--,j++)
            if(chessboard[i][j]=='Q')return false;
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, std::string(n, '.'));
        backtracking(n, chessboard,0);
        return res;
    }
};
