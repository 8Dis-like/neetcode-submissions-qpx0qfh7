class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len=0;
        int res=0;
        unordered_set<int>s;
        for(int num:nums)s.insert(num);
        for(int num:nums){
            if(s.count(num-1))continue;
            else while(s.count(num++))len++;
            res=len>res?len:res;
            len=0;
        }return res;
    }
};
