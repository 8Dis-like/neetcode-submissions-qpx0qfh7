class LRUCache {
struct dlinknode{
    int key,val;
    dlinknode* prev;
    dlinknode* next;
    dlinknode(int key,int val):key(key),val(val),prev(nullptr),next(nullptr){}
};
public:
    LRUCache(int capacity):size(0),capacity(capacity) {
        head=new dlinknode(0,0);
        tail=new dlinknode(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        else{
            dlinknode* node=mp[key];
            removenode(node);
            addtohead(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            dlinknode* node=mp[key];
            node->val=value;
            removenode(node);
            addtohead(node); 
        }else{
            mp[key]=new dlinknode(key,value);
            size++;
            addtohead(mp[key]);
            if(size>capacity){
                dlinknode* node=removetail();
                mp.erase(node->key);
                size--;
            }
        }
    }

    void addtohead(dlinknode* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }

    void removenode(dlinknode* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->prev=nullptr;
        node->next=nullptr;
    }

    dlinknode* removetail(){
        dlinknode* node=tail->prev;
        tail->prev=node->prev;
        node->prev->next=tail;
        node->prev=nullptr;
        node->next=nullptr;
        return node;
    }
    
private: 
    int capacity;
    int size;
    dlinknode* head;
    dlinknode* tail;
    unordered_map<int,dlinknode*>mp;
};
