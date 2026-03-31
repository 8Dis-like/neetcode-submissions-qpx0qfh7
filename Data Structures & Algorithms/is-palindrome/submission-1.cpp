class Solution {
public:
    bool isPalindrome(string s) {
        stack<char>st;
        string ss="";
        for(char c:s){
            c=tolower(c);
            if((c-'a'>=0)&&(c-'a'<26)||(c-'0'>=0)&&(c-'0'<9))ss+=c;
        }
        int len=ss.length();
        for(int i=0;i<len/2;i++)st.push(ss[i]);
        int idx=len%2==0?len/2:len/2+1;
        for(int i=idx;i<len;i++){
            if(ss[i]!=st.top())return false;
            st.pop();
        }return st.empty();
    }
};
