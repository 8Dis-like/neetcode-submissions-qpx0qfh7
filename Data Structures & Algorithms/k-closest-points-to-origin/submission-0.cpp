class Solution {
public:
struct Point{
    vector<int> cords;
    int dist;
    Point(vector<int>& cords):cords(cords){
        dist=cords[0]*cords[0]+cords[1]*cords[1];
    }
    // Overload the < operator to create a Max-Heap based on distance
    bool operator<(const Point& other) const {
        return dist < other.dist; 
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point>pq;
        for(auto point: points){
            Point p(point);
            if(pq.empty()||pq.size()<k)pq.push(p);
            else{
                Point t=pq.top();
                if(t.dist>=p.dist){
                    pq.pop();
                    pq.push(p);
                }else continue;
            }
        }vector<vector<int>> res;
        while(!pq.empty()){
            Point p=pq.top();
            res.push_back(p.cords);
            pq.pop();
        }return res;
    }
};
