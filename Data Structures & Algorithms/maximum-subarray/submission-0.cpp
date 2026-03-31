class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count=0;
        int maxsum=INT_MIN;
        for(auto num:nums){
            count+=num;
            maxsum=maxsum>count?maxsum:count;
            if(count<0)count=0;
        }return maxsum;
    }
};
