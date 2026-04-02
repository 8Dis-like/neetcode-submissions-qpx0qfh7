class Solution {
public:
    inline int idx(char c){
        if(c>='A'&&c<='Z')return c-'A';
        else return 26+(c-'a');
    }
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";
        int scnt[52]={0};
        int tcnt[52]={0};
        int required=0;
        for(char c:t){
            int id=idx(c);
            if(tcnt[id]==0)required++;
            tcnt[id]++;
            }
        int formed=0;
        int l=0,bestl=0,bestlen=INT_MAX;
        for(int r=0;r<s.size();r++){
            int idr=idx(s[r]);
            scnt[idr]++;
            if(tcnt[idr]>0&&scnt[idr]==tcnt[idr])formed++;
            while(l<=r&&formed==required){
                if(r-l+1<bestlen){
                    bestlen=r-l+1;
                    bestl=l;
                }
                int idl=idx(s[l]);
                scnt[idl]--;
                if(tcnt[idl]>0&&scnt[idl]<tcnt[idl])formed--;
                l++;
            }
        }if(bestlen==INT_MAX)return "";
        return s.substr(bestl,bestlen);
    }
};
