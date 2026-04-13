class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size=nums.size();
        int sum=0;
        for(auto num:nums)sum+=num;
        if(sum%2==1)return false;
        int target=sum/2;
        vector<int>dp(5000,0);
        for(int i=0;i<size;i++){
            for(int j=target;j>=nums[i];j--){
                dp[j]=max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }return target==dp[target];
    }
};
