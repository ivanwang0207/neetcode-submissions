class Solution {

private: 
    void dfs(vector<vector<char>>& grid, int i, int j) {
        char currElem = grid[i][j];
        if (currElem == '0') {
            return;
        }
        // mark the element as visited
        grid[i][j] = '2';

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto& [dx, dy] : dirs) {
            if (i + dy < grid.size() && i + dy >= 0 &&
                j + dx < grid[0].size() && j + dx >= 0 &&
                grid[i + dy][j + dx] != '2') {
                dfs(grid, i + dy, j + dx);
            }
        }
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()) {
            auto& [ci, cj] = q.front();
            q.pop();

            if (grid[ci][cj] != '1') continue;
            grid[ci][cj] = '2';  // visited

            for(auto& [dx, dy] : dirs) {
                if (ci + dy < grid.size() && ci + dy >= 0 &&
                    cj + dx < grid[0].size() && cj + dx >= 0 &&
                    grid[ci + dy][cj + dx] != '2') {
                    q.push({ci + dy, cj + dx});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        int count = 0;

        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j); // inplace update
                }
            }
        }
        return count;
    }
};
