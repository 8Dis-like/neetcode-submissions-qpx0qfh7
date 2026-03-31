class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minhp.empty()||num>minhp.top())minhp.push(num);
        else maxhp.push(num);
        if(minhp.size()>maxhp.size()+1){maxhp.push(minhp.top());minhp.pop();}
        if(minhp.size()+1<maxhp.size()){minhp.push(maxhp.top());maxhp.pop();}
    }
    
    double findMedian() {
        if(minhp.size()-maxhp.size()==1)return (double)minhp.top();
        if(maxhp.size()-minhp.size()==1)return (double)maxhp.top();
        else return ((double)(maxhp.top()+minhp.top()))/2.0;
    }
private:
    priority_queue<int>maxhp;
    priority_queue<int,vector<int>,greater<int>>minhp;
};
