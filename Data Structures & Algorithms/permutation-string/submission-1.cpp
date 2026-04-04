class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>cnt1(26,0);
        vector<int>cnt2(26,0);
        for(char c :s1)cnt1[c-'a']++;
        int len=s1.length();
        int i=0;
        for(int j=0;j<s2.size();j++){
            cnt2[s2[j]-'a']++;
            if (j - i + 1 > len) {
                cnt2[s2[i] - 'a']--;
                i++;
            }
            if(i+len==j+1)if(cnt1==cnt2)return true;
        }
        return false;
    }
};
