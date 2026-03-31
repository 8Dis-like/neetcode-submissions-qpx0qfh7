class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        int res=0;
        vector<int>dp(size,1);
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])dp[i]=max(dp[i],dp[j]+1);
            }res=res>dp[i]?res:dp[i];
        }return res;
    }
};
