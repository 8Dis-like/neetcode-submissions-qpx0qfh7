class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            auto idx=mp.find(diff);
            if(idx!=mp.end())return vector<int>{idx->second,i};
            else mp[nums[i]]=i;
        }
    }
};
