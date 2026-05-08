class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>nn(n+2,1);
        for(int i=0;i<n;i++)nn[i+1]=nums[i];
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int l=n;l>=1;l--){
            for(int r=l;r<=n;r++){
                for(int k=l;k<=r;k++){
                    int coins=nn[l-1]*nn[r+1]*nn[k];
                    coins+=dp[l][k-1]+dp[k+1][r];
                    dp[l][r]=max(dp[l][r],coins);
                }
            }
        }return dp[1][n];
    }
};
