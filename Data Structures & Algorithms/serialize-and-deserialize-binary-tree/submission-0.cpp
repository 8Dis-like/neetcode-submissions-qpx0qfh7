class Codec {
public:
    // Encodes a tree to a single string using Pre-Order DFS.
    string serialize(TreeNode* root) {
        if (!root) return "N,";
        // Pre-order: Root, Left, Right
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> vals = split(data, ',');
        int i = 0;
        return desdfs(vals, i);
    }

private:
    // Notice the & on int& i to keep the index updated across recursion!
    TreeNode* desdfs(vector<string>& vals, int& i) {
        if (i >= vals.size()) return nullptr; // Safety check
        
        if (vals[i] == "N") {
            i++; // Must increment past the "N" before returning!
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++; // Increment past the current value
        
        node->left = desdfs(vals, i);
        node->right = desdfs(vals, i);
        
        return node;
    }

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