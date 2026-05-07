class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int>dp;
        dp[0]=1;
        for(auto num:nums){
            unordered_map<int,int>tmp;
            for(auto& dpt:dp){
                tmp[dpt.first+num]+=dpt.second;
                tmp[dpt.first-num]+=dpt.second;
            }dp=tmp;
        }return dp[target];
    }
};
