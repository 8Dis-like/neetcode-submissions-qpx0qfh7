class Solution {
public:
    vector<int> partitionLabels(string s) {
      unordered_map<char,int>last;
      for(int i=0;i<s.size();i++)last[s[i]]=i;
      int size=0;
      int end=0;
      vector<int>res;
      for(int j=0;j<s.size();j++){
        size++;
        end=max(end,last[s[j]]);
        if(j==end){
            res.push_back(size);
            size=0;
        }
      }  return res;
    }
};
