class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        for(auto num:nums)cnt[num]++;
        vector<vector<int>>freq(nums.size()+1);
        for(auto frq:cnt){
            freq[frq.second].push_back(frq.first);
        }
        vector<int> res;
       for(int i=freq.size()-1;i>=0;i--){
         for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
       }
    }
};
