class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto tk:tokens){
            if(tk=="+" || tk=="-" || tk=="*" || tk=="/"){
                int val=st.top(); st.pop();
                int tmp=st.top(); st.pop();
                if(tk=="+"){st.push(tmp+val);}
                if(tk=="-"){st.push(tmp-val);}
                if(tk=="*"){st.push(tmp*val);}
                if(tk=="/"){st.push(tmp/val);}
            }
            else st.push(stoi(tk));
        }return st.top();
    }
};
