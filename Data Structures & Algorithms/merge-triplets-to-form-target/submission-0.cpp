class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x=false,y=false,z=false;
        for(auto &trip:triplets){
            x|=(trip[0]==target[0]&&trip[1]<=target[1]&&trip[2]<=target[2]);
            y|=(trip[0]<=target[0]&&trip[1]==target[1]&&trip[2]<=target[2]);
            z|=(trip[0]<=target[0]&&trip[1]<=target[1]&&trip[2]==target[2]);
        }return x&&y&&z;
    }
};
