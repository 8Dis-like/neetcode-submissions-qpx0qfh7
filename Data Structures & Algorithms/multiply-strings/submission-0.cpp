class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        if(num1.size()<num2.size())return multiply(num2,num1);
        string res="";
        int zero=0;
        for(int i=num2.size()-1;i>=0;i--){
            string cur=mul(num1,num2[i],zero);
            zero++;
            res=add(cur,res);
        }
        return res;
    }
    string mul(string s,char d,int zero){
        string cur;
        int digit=d-'0';
        int i=s.size()-1,carry=0;
        while(i>=0||carry){
            int n=(i>=0)?s[i]-'0':0;
            int prod=n*digit+carry;
            cur.push_back((prod%10)+'0');
            carry=prod/10;
            i--;
        }reverse(cur.begin(),cur.end());
        return cur+string(zero,'0');
    }

    string add(string num1,string num2){
        int i=num1.size()-1,j=num2.size()-1,carry=0;
        string res;
        while(i>=0||j>=0||carry){
            int n1=(i>=0)?num1[i]-'0':0;
            int n2=(j>=0)?num2[j]-'0':0;
            int sum=n1+n2+carry;
            res.push_back((sum%10)+'0');
            carry=sum/10;
            i--;
            j--;
        }reverse(res.begin(),res.end());
        return res;
    }
};
