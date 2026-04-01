class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // 1. Initialize adjacency list for all unique characters
        unordered_map<char, unordered_set<char>> adj;
        for (const string& w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>(); 
            }
        }

        // 2. Build the graph by finding the first differing character
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());

            // Invalid prefix condition: w1 is longer and w1 completely starts with w2
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }

            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        // 3. Setup for DFS
        // false = fully visited, true = currently in path (used to detect cycles)
        unordered_map<char, bool> visit; 
        string res = "";

        // 4. Define the DFS lambda function
        // We pass 'self' so the lambda can call itself recursively
        auto dfs = [&](auto& self, char c) -> bool {
            if (visit.count(c)) {
                return visit[c];
            }

            visit[c] = true; // Mark as currently visiting

            for (char nei : adj[c]) {
                if (self(self, nei)) {
                    return true; // Cycle detected
                }
            }

            visit[c] = false; // Mark as fully visited
            res.push_back(c);
            return false; // Explicitly returning false (matching Python's implicit 'None')
        };

        // 5. Run DFS on all characters in the graph
        for (auto const& [c, neighbors] : adj) {
            if (dfs(dfs, c)) {
                return ""; // Cycle detected, return empty string
            }
        }

        // 6. Reverse post-order to get the valid topological sort
        reverse(res.begin(), res.end());
        return res;
    }
};