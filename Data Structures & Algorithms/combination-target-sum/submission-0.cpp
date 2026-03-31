class Solution {
public:
    vector<vector<int>> res;
    vector<int>path;
    void backtracing(vector<int>&nums,int target, int sum,int idx){
        if(target<sum)return;
        if(target==sum){res.push_back(path);return;}
        for(int i=idx;i<nums.size();i++){
            path.push_back(nums[i]);
            sum+=nums[i];
            backtracing(nums,target,sum,i);
            sum-=nums[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtracing(nums,target,0,0);
        return res;
    }
};
