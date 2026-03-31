class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool>dp(s.length()+1,false);
    dp[0]=true;
    for(int i=1;i<=s.length();i++){
        for(const string w:wordDict){
            if(i>=w.length()&&s.substr(i-w.length(),w.length())==w)dp[i]=dp[i-w.length()];
            if(dp[i])break;
        }
    }
    return dp[s.length()];
    }
};
