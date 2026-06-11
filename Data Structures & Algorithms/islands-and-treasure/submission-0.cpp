class Solution {
public:
    void dfs(int m, int n, vector<vector<int>>& grid, int distance) {
        
        int row = grid.size();
        int col = grid[0].size();

        // stop point: out of bound
        if (m < 0 || m >= row || n < 0 || n >= col)
            return;
        // stop point: the distance in the grid is smaller 
        // encounter the wall or the previous traverse distance is smaller
        if (grid[m][n] == -1 || grid[m][n] < distance)
            return;

        grid[m][n] = distance;
        dfs(m + 1, n, grid, distance + 1);
        dfs(m - 1, n, grid, distance + 1);
        dfs(m, n + 1, grid, distance + 1);
        dfs(m, n - 1, grid, distance + 1);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (grid[i][j] == 0)
                    dfs(i, j, grid, 0);
            }
        }
    }
};

// BFS solution
// class Solution {
// public:
//     void wallsAndGates(vector<vector<int>>& rooms) {
//         queue<pair<int, int>> q;
//         vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
//         for (int i = 0; i < rooms.size(); ++i) {
//             for (int j = 0; j < rooms[i].size(); ++j) {
//                 if (rooms[i][j] == 0) q.push({i, j});   
//             }
//         }
//         while (!q.empty()) {
//             int i = q.front().first, j = q.front().second; q.pop();
//             for (int k = 0; k < dirs.size(); ++k) {
//                 int x = i + dirs[k][0], y = j + dirs[k][1];
//                 if (x < 0 || x >= rooms.size() || 
//                     y < 0 || y >= rooms[0].size() || 
//                     rooms[x][y] < rooms[i][j] + 1) 
//                     continue;

//                 rooms[x][y] = rooms[i][j] + 1;
//                 q.push({x, y});
//             }
//         }
//     }
// };
