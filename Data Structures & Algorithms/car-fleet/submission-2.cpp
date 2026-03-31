class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size=position.size();
        unordered_map<int,int>idx;
        for(int i=0;i<size;i++)idx[position[i]]=i;
        vector<double>times(size,0);
        sort(position.rbegin(),position.rend());
        for(int i=0;i<size;i++)
            times[i]=(double)(target-position[i])/speed[idx[position[i]]];
        stack<int>st;
        for(int i=0;i<size;i++){
            if(!st.empty()&&times[st.top()]>=times[i])continue;
            else st.push(i);
        }
        int res=0;
        while(!st.empty()){res++;st.pop();}
        return res;
    }
};
