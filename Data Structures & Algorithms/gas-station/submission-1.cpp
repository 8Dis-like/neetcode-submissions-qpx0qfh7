class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=gas.size();
        int gt=0,ct=0;
        for(int i=0;i<s;i++){
            gt+=gas[i];
            ct+=cost[i];
        }if(gt<ct)return -1;
        int total=0;
        int id=0;
        for(int i=0;i<s;i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            if(total<0){
                total=0;
                id=i+1;
            }
        }return id;
    }
};
