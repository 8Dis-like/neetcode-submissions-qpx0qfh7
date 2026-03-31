class WordDictionary {
private:
    struct TrieNode {
        bool isend;
        TrieNode* children[26];

        TrieNode() : isend(false) {
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    
    TrieNode* root;

    // We replace 'search' and 'traversal' with one clean recursive helper
    bool searchHelper(const string& word, int index, TrieNode* node) {
        // Base case: if we've reached the end of the word, check if it's a valid end node
        if (index == word.size()) {
            return node->isend;
        }

        char c = word[index];

        if (c == '.') {
            // Wildcard: Try all 26 possible children
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (searchHelper(word, index + 1, node->children[i])) {
                        return true; // We found a valid path!
                    }
                }
            }
            return false; // None of the 26 paths worked
        } else {
            // Standard character: Just follow the single path
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            return searchHelper(word, index + 1, node->children[idx]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode(); // Fixed shadowing bug!
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }
        cur->isend = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};