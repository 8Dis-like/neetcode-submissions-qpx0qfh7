class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>freq;
        for(auto h:hand)freq[h]++;
        sort(hand.begin(),hand.end());
        int id=0;
        while(id<hand.size()){
            for(int k=hand[id];k<hand[id]+groupSize;k++){
                if(freq.find(k)!=freq.end()&&freq[k]>0)freq[k]--;
                else return false;
            }
            while(freq[hand[id]]==0&&id<hand.size())id++;
        }return true;
    }
};
