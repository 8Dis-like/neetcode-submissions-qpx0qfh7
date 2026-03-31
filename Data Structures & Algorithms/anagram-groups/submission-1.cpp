class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        for(string str:strs){
            int cnt[26]={};
            for(char c:str)cnt[c-'a']++;
            string key=to_string(cnt[0]);
            for(int i=1;i<26;i++)key+=','+to_string(cnt[i]);
            res[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto & r:res){
            result.push_back(r.second);
        }
        return result;
    }
};
