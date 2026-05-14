class Solution {
public:
    bool checkValidString(string s) {
        // 2 stacks storing ( and * indices
        stack<int>l;
        stack<int>a;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')l.push(i);
            if(s[i]=='*')a.push(i);
        // *->) 
            if(s[i]==')'){
                if(!l.empty())l.pop();
                else if(!a.empty())a.pop();
                else return false;
            }
        }
        // *->(
        while(!l.empty()&&!a.empty()){
            if(l.top()<a.top()){
                l.pop();
                a.pop();
            }else return false;
        }
        return l.empty();
    }
};
