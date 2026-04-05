class Solution {
public:
    vector<string>res;
    string path;
    void backtracking(int n, int open, int close){
        if(path.size()==2*n)res.push_back(path);
        if(open<n){
            path+='(';
            backtracking(n,open+1,close);
            path.pop_back();
        }
        if(close<open){
            path+=')';
            backtracking(n,open,close+1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtracking(n,0,0);
        return res;
    }
};
