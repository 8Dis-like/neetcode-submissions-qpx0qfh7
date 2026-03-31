class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int len=s.length();
        unordered_set<char>sc;
        for(int i=0,j=0;j<len;j++){
            while(sc.count(s[j])){
                sc.erase(s[i]);
                i++;
            }sc.insert(s[j]);
            res = max(res, j - i + 1);
        }
        return res;
    }
};
