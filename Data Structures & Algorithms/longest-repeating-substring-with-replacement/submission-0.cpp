class Solution {
public:
    int characterReplacement(string s, int k) {
        int len=s.length();
        vector<int>cnt(26,0);
        int maxcnt=0;
        int l=0,r=0;
        int res=0;
        while(r<len){
            int idxr=s[r]-'A';
            cnt[idxr]++;
            maxcnt=maxcnt>cnt[idxr]?maxcnt:cnt[idxr];
            while(r-l+1-maxcnt>k){
                int idxl=s[l]-'A';
                cnt[idxl]--;
                l++;
            }res=max(res,r-l+1);
            r++;
        }return res;
    }
};
