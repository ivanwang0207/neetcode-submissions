class Solution {
public:

    void countMaxArea(int r, int c, int& localCount, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        
        visited[r][c] = 1;
        if (grid[r][c] == 0)
            return;

        int r_max = grid.size();
        int c_max = grid[0].size();
        localCount++;

        // up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // explore each direction
        for (const auto& dir : directions) {
            int new_r = r + dir.first;
            int new_c = c + dir.second;

            if (new_r >= 0 && new_r < r_max 
                && new_c >= 0 && new_c < c_max 
                && !visited[new_r][new_c]) {
                countMaxArea(new_r, new_c, localCount, grid, visited);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r_count = grid.size();
        int c_count = grid[0].size();
        vector<vector<bool>> visited(r_count, vector<bool>(c_count, 0));
        int maxCount = 0;

        for(int i = 0; i < r_count; i++){
            for(int j = 0; j < c_count; j++){
                if (grid[i][j] == 1 && !visited[i][j]){
                    int localCount = 0;
                    countMaxArea(i, j, localCount, grid, visited);

                    maxCount = max(maxCount, localCount);
                }
            }
        }
        return maxCount;
    }

};


