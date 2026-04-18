class Solution {
public:
    vector<string>path;
    vector<vector<string>>res;

    bool ispalindrom(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }return true;
    }

    void backtracking(string s,int start){
        if(start>=s.size()){
            res.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(!ispalindrom(s,start,i))continue;
            else{
                string str=s.substr(start,i-start+1);
                path.push_back(str);
                backtracking(s,i+1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return res;
    }
};
