class Solution {
public:
    int numDistinct(string s, string t) {
        int sl=s.size();
        int tl=t.size();
        vector<vector<int>>dp(sl+1,vector<int>(tl+1,0));
        for(int i=0;i<=sl;i++)dp[i][0]=1;
        for(int i=1;i<=sl;i++){
            for(int j=1;j<=tl;j++){
                if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }return dp[sl][tl];
    }
};
