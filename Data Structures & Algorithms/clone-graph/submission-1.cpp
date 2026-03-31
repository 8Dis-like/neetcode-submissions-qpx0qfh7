/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>old2new;        
        return dfs(node,old2new);
    }
    Node* dfs(Node*node,map<Node*,Node*>&old2new){
        if(!node)return nullptr;
        if(old2new.count(node))return old2new[node];
        else{
            Node* copy=new Node(node->val);
            old2new[node]=copy;
            for(auto nei:node->neighbors){
                copy->neighbors.push_back(dfs(nei,old2new));
        }return copy;
            }
    }
};
