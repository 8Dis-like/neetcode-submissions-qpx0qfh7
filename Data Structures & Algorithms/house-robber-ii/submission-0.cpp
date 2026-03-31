class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int size=nums.size();
        int rob1=robbery(nums,1,size-1);
        int rob2=robbery(nums,0,size-2);
        return max(rob1,rob2);
    }
    int robbery(vector<int>& nums,int start,int end){
        if(start==end)return nums[start];
        vector<int>dp(nums.size(),0);
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++)dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        return dp[end];
    }
};
