class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Edge cases
        if (rows == 0 || cols == 0)
            return {};

        // Visitation grids for Pacific and Atlantic
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        // Perform DFS from Pacific and Atlantic edges
        for (int i = 0; i < rows; ++i) {
            dfs(heights, pacific, i, 0);           // Left edge (Pacific)
            dfs(heights, atlantic, i, cols - 1);   // Right edge (Atlantic)
        }
        for (int j = 0; j < cols; ++j) {
            dfs(heights, pacific, 0, j);           // Top edge (Pacific)
            dfs(heights, atlantic, rows - 1, j);   // Bottom edge (Atlantic)
        }

        // Collect cells that can flow to both oceans
        vector<vector<int>> result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(const vector<vector<int>>& heights, vector<vector<int>>& visited, int x, int y) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Mark the current cell as visited
        visited[x][y] = 1;

        // Direction vectors for exploring neighbors
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            // Check boundaries, visitation status, and flow condition
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && 
                !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                dfs(heights, visited, nx, ny);
            }
        }
    }
};
