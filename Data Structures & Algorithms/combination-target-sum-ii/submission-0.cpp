class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void backtracking(vector<int>&candidates, int target, int startidx, vector<bool>used){
        if(target==0){res.push_back(path);return;}
        if(target<0)return;
        int size=candidates.size();
        for(int i=startidx;i<size;i++){
            if(i>0&&candidates[i]==candidates[i-1]&&!used[i-1])continue;
            path.push_back(candidates[i]);
            used[i]=true;
            backtracking(candidates,target-candidates[i],i+1,used);
            used[i]=false;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<bool>used(size,false);
        backtracking(candidates,target,0,used);
        return res;
    }
};
