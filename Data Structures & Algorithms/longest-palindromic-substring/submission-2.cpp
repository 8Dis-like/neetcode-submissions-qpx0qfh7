class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        if (len == 0) return "";
        int maxlen=1;
        int start=0;
        vector<vector<bool>>dp(len,vector<bool>(len,false));
        for(int i=0;i<len;i++)dp[i][i]=true;
        for(int i=len-1;i>=0;i--){
            for(int j=i+1;j<len;j++){
                if(s[i]==s[j]){
                    if(j-i==1||dp[i+1][j-1]){
                        dp[i][j]=true;
                        if (j - i + 1 > maxlen) {
                            maxlen = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
        }return s.substr(start,maxlen);
    }
};
