class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>dict;
        for(char c:s)dict[c]++;
        for(char w:t){
            if(dict.find(w)==dict.end())return false;
            else{
                dict[w]--;
            }
        }
        for(unordered_map<char,int>::iterator it=dict.begin();it!=dict.end();it++){
            if(it->second!=0)return false;
        }return true;
    }
};
