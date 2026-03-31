class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // 1. Initialize the father array directly here (fixes the memory bug)
        vector<int> father(n);
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
        
        // 2. Start by assuming every node is its own separate component
        int components = n;
        
        // 3. Process edges
        for (auto& edge : edges) {
            // If we successfully joined two separate components, decrease our total count
            if (join(edge[0], edge[1], father)) {
                components--;
            }
        }
        
        return components; // No sets needed!
    }

private:
    // Notice we pass 'father' into the recursive call!
    int find(int u, vector<int>& father) {
        if (u == father[u]) return u;
        // Path compression
        return father[u] = find(father[u], father); 
    }

    // Changed to return a bool so we know if a merge actually happened
    bool join(int u, int v, vector<int>& father) {
        int rootU = find(u, father); // Fixed missing argument
        int rootV = find(v, father); // Fixed missing argument
        
        if (rootU == rootV) {
            return false; // They are already in the same component
        }
        
        father[rootV] = rootU; // Merge them
        return true;           // Successfully merged
    }
};