class Solution {
public:
    bool res=false;
    void backtracing(vector<vector<char>>& board, string word,int idx,int i,int j){
        if(idx==word.size()){res=true;return;}
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        backtracing(board,word,idx+1,i-1,j);
        backtracing(board,word,idx+1,i,j+1);
        backtracing(board,word,idx+1,i+1,j);
        backtracing(board,word,idx+1,i,j-1);
        board[i][j]=temp;
        }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                backtracing(board,word,0,i,j);
            }
        }
        return res;
    }
};
