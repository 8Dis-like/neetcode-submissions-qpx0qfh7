class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        int len=s.length();
        vector<vector<bool>>dp(len,vector<bool>(len,false));
        for(int i=0;i<len;i++)dp[i][i]=true;
        for(int i=len-1;i>=0;i--){
            for(int j=i;j<len;j++){
                if(s[i]==s[j]){
                    if(j-i<=1||dp[i+1][j-1]){
                        dp[i][j]=true;
                        res++;
                    }
                }
            }
        }return res;
    }
};
