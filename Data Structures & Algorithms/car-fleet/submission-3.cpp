class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size=position.size();
        vector<pair<int,int>>pairs;
        for(int i=0;i<size;i++)pairs.push_back({position[i],speed[i]});
        sort(pairs.rbegin(),pairs.rend());
        int fleets=1;
        double prevtime=(double)(target-pairs[0].first)/pairs[0].second;
        for(int i=1;i<size;i++){
            double curtime=(double)(target-pairs[i].first)/pairs[i].second;
        if(curtime>prevtime){
            fleets++;
            prevtime=curtime;
        }
        }return fleets;
    }
};
