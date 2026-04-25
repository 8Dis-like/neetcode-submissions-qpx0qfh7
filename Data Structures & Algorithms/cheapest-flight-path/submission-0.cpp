class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> minDist(n + 1 , INT_MAX);
        minDist[src] = 0;
        vector<int> minDist_copy(n + 1); 
        for(int i=0;i<k+1;i++){
            minDist_copy=minDist;
            for(auto f:flights){
                int from=f[0];
                int to=f[1];
                int price=f[2];
                if(minDist_copy[from]!=INT_MAX&&minDist_copy[from]+price<minDist[to])minDist[to]=minDist_copy[from]+price;
            }
        }
        return (minDist[dst]==INT_MAX)?-1:minDist[dst];
    }
};
