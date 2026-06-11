class Solution {

private:
    void checkOccupation(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        char status = grid[i][j];
        visited[i][j] = 1;  // mark current element as visited

        if (status != '1') return;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto& d : directions){
            int new_i = i + d.first;
            int new_j = j + d.second;
            if (new_i < 0 || new_i > grid.size() - 1 || 
                new_j < 0 || new_j > grid[0].size() - 1) 
                continue;

            if (visited[new_i][new_j])
                continue;

            checkOccupation(grid, visited, new_i, new_j);
        }
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        int count = 0;

        vector<vector<bool>> visited(h, vector<bool>(w, 0));
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {

                // the first '1' is found, so we keep expanding its surrounding elements
                // with the checkOccupation function, which is a DFS function that recursively 
                // find the element with four directions for the current element.
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    checkOccupation(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};
