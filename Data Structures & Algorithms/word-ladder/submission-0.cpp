class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(!s.count(endWord))return 0;
        unordered_map<string,int>vis;
        queue<string>q;
        q.push(beginWord);
        vis[beginWord]=1;
        while(!q.empty()){
            string word=q.front();q.pop();
            int path=vis[word];
            for(int i=0;i<word.size();i++){
                string nw=word;
                for(int j=0;j<26;j++){
                    nw[i]=j+'a';
                    if(nw==endWord)return path+1;
                    if(s.count(nw)&&vis.find(nw)==vis.end()){
                        vis[nw]=path+1;
                        q.push(nw);
                    }
                }
            }
        }return 0;
    }
};
