class TrieNode{
public:
    bool isend;
    unordered_map<char,TrieNode*>children;

    TrieNode():isend(false){}

    void addword(const string &word){
        TrieNode* cur=this;
        for(char c:word){
            if(!cur->children.count(c))
                cur->children[c]=new TrieNode();
        cur=cur->children[c];
        }cur->isend=true;
    }
};

class Solution {
    unordered_set<string>res;
    vector<vector<bool>>vis;
private:
    void dfs(vector<vector<char>>& board,int r,int c,TrieNode*node,string word){
        int rows=board.size();int cols=board[0].size();
        if(r<0||c<0||r>=rows||c>=cols||vis[r][c]||!node->children.count(board[r][c]))return;
        vis[r][c]=true;
        node=node->children[board[r][c]];
        word+=board[r][c];
        if(node->isend)res.insert(word);
        dfs(board,r-1,c,node,word);
        dfs(board,r+1,c,node,word);
        dfs(board,r,c-1,node,word);
        dfs(board,r,c+1,node,word);
        vis[r][c]=false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(const string &word:words)root->addword(word);

        int rows=board.size();int cols=board[0].size();
        vis.assign(rows,vector<bool>(cols,false));
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                dfs(board,r,c,root,"");
            }
        }return vector<string>(res.begin(),res.end());
    }
};
