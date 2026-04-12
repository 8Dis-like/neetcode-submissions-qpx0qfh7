class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto num:nums){
            if(pq.empty()||pq.size()<k)pq.push(num);
            else{
                int tmp=pq.top();
                if(num<=tmp)continue;
                else {
                    pq.pop();
                    pq.push(num);
                }
            }
        }return pq.top();
    }
};
