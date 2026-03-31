class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int minp=1;
        int maxp=1;
        for(auto num:nums){
            int tmp=num*maxp;
            maxp=max(num,max(num*maxp,num*minp));
            minp=min(num,min(num*minp,tmp));
            res=max(res,maxp);
        }
        return res;
    }
};
