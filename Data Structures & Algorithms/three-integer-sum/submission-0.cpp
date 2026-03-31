class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size();k++){
            if (k > 0 && nums[k] == nums[k-1]) continue;
            int i=k+1,j=nums.size()-1;
            int target=-nums[k];
        while(i<j){
            if(nums[i]+nums[j]==target) {
                res.push_back(vector<int>{nums[k],nums[i],nums[j]});
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                i++; j--;
            }
            else if(nums[i]+nums[j]>target)j--;
            else i++;
        }
        }
        return res;
    }
};