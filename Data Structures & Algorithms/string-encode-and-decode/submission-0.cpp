class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(string str:strs){
            int len=str.length();
            res+=to_string(len);
            res+="#";
            res+=str;
        }return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        for(int i=0;i<s.length();){
            string len="";
            while(s[i]!='#')len+=s[i++];
            if(s[i]=='#'){
            int leng=stoi(len);
            i++;
            res.push_back(s.substr(i,leng));
            i+=leng;
            }
        }return res;
    }
};
