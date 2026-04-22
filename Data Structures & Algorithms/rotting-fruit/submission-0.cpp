class Solution {
public:
    int dir[5] = {1, 0, -1, 0, 1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_count = 0; // Track fresh oranges
        
        // Push initially rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        
        // If there are no fresh oranges to begin with, it takes 0 minutes!
        if (fresh_count == 0) return 0;
        
        int minutes = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool rotted_this_minute = false; // Flag to prevent overcounting
            
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
            
                for (int j = 0; j < 4; j++) {
                    int nx = r + dir[j];
                    int ny = c + dir[j + 1];
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh_count--; // Decrement our fresh counter
                        rotted_this_minute = true; 
                    }
                }
            }
            // Only increment time if we actually did work this level
            if (rotted_this_minute) minutes++;
        }
        
        // If we still have fresh oranges left over, they are unreachable
        return fresh_count == 0 ? minutes : -1;
    }
};