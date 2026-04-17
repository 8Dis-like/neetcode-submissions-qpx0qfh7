class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void backtracking(vector<int>& nums,int startidx){
            res.push_back(path);
        if(startidx>=nums.size())
            return;
        for(int i=startidx;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return res;
    }
};
