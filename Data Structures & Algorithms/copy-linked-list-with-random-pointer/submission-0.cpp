/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>old2new;
        Node* cur=head;
        while(cur){
            Node* copy=new Node(cur->val);
            old2new[cur]=copy;
            cur=cur->next;
        }
        cur=head;
        while(cur){
            old2new[cur]->next=old2new[cur->next];
            old2new[cur]->random=old2new[cur->random];
            cur=cur->next;
        }return old2new[head];
    }
};
