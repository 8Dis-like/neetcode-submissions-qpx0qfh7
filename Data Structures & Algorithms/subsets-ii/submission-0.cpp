class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void backtracking(vector<int>& nums,int startidx,vector<bool>&used){
            res.push_back(path);
        if(startidx>=nums.size())
            return;
        for(int i=startidx;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)continue;
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums,i+1,used);
            used[i]=false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        sort(nums.begin(),nums.end());
        backtracking(nums,0,used);
        return res;
    }
};
