class PrefixTree {
private:
    struct TrieNode{
        bool isend;
        TrieNode* children[26];

        TrieNode():isend(false){
            for(int i=0;i<26;i++)children[i]=nullptr;
        }
    };
    TrieNode* root;
public:
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for(char c:word){
            int idx=c-'a';
            if(cur->children[idx]==nullptr)cur->children[idx]=new TrieNode();
            cur=cur->children[idx];
        }cur->isend=true;
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(char c:word){
            int idx=c-'a';
            if(cur->children[idx]==nullptr)return false;
            cur=cur->children[idx];
        }return cur->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char c:prefix){
            int idx=c-'a';
            if(cur->children[idx]==nullptr)return false;
            cur=cur->children[idx];
        }return true;
    }
};
