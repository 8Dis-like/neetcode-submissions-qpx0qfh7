class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size=0;
public:
    KthLargest(int k, vector<int>& nums) {
        if(nums.size()==0)return;
        //maintain the top k elements in a min-heap
        size=k;
        sort(nums.begin(),nums.end());
        int len=k>nums.size()?nums.size():k;
        for(int i=0;i<len;i++)pq.push(nums[nums.size()-1-i]);
    }
    
    int add(int val) {
        if(pq.empty()||pq.size()<size){pq.push(val);return pq.top();}
        int minv=pq.top();
        if(val<=minv)return minv;
        else {
            pq.pop();
            pq.push(val);
            return pq.top();
        }
    }
};
