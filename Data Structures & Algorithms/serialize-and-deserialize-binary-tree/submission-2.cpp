class Codec {
public:
    // Your original BFS serialization
    string serialize(TreeNode* root) {
        string res = "";
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node == nullptr) {
                res += "N,";
            } else {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // New BFS deserialization
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        vector<string> vals = split(data, ',');
        
        // If the first element is "N" or empty, the tree is empty
        if (vals.empty() || vals[0] == "N") return nullptr;

        // Create the root and a queue to track parents
        TreeNode* root = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        
        int i = 1; // Start reading from the second element (index 1)
        
        while (!q.empty() && i < vals.size()) {
            TreeNode* curr = q.front();
            q.pop();
            
            // 1. Process the Left Child
            // (We check vals[i] != "" to handle the trailing comma from split)
            if (i < vals.size() && vals[i] != "N" && vals[i] != "") {
                curr->left = new TreeNode(stoi(vals[i]));
                q.push(curr->left);
            }
            i++; // Always increment, even if it was "N"
            
            // 2. Process the Right Child
            if (i < vals.size() && vals[i] != "N" && vals[i] != "") {
                curr->right = new TreeNode(stoi(vals[i]));
                q.push(curr->right);
            }
            i++; // Always increment, even if it was "N"
        }
        
        return root;
    }

private:
    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
};