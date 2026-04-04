class Solution {
private:
    class Myque{
        public:
        deque<int>que;
        //pop if current val == front
        void pop(int val){
            if(!que.empty()&&que.front()==val)que.pop_front();
        }
        //push from back to keep the queue decreasing
        void push(int val){
            while(!que.empty()&&val>que.back())que.pop_back();
            que.push_back(val);
        }
        int getmax(){
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myque que;
        for(int i=0;i<k;i++)que.push(nums[i]);
        int size=nums.size();
        vector<int>res;
        res.push_back(que.getmax());
        for(int i=k;i<size;i++){
            que.push(nums[i]);
            que.pop(nums[i-k]);
            res.push_back(que.getmax());
        }return res;
    }
};
