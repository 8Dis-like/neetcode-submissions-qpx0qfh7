class Solution {
public:
    int sum(int n){
        int output=0;
        while(n){
            int digit=n%10;
            digit*=digit;
            output+=digit;
            n/=10;
        }return output;
    }
    bool isHappy(int n) {
        unordered_set<int>vis;
        while(vis.find(n)==vis.end()){
            vis.insert(n);
            n=sum(n);
            if(n==1)return true;
        }return false;
    }
};
