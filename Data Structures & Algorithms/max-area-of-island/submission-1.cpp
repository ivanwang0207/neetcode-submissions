class Solution {

private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        area++;
        int height = grid.size();
        int width = grid[0].size();
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        grid[i][j] = -1;

        for(auto& d : directions) {
            int new_i = i + d[0];
            int new_j = j + d[1];
            if (new_i >= 0 && new_i < height && 
                new_j >= 0 && new_j < width && 
                grid[new_i][new_j] == 1) {
                dfs(grid, new_i, new_j, area);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                // execute dfs or bfs
                if (grid[i][j] == 1){
                    int currArea = 0;
                    dfs(grid, i, j, currArea);

                    if (currArea > maxArea) 
                        maxArea = currArea;
                }
            }
        }
        return maxArea;
    }
};
