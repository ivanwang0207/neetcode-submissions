class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS method 
        queue<pair<int, int>> q;
        int h = grid.size();
        int w = grid[0].size();
        int fresh_count = 0;

        // add the first rotten fruit in the queue
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                    fresh_count++;
            }
        }
        if (fresh_count == 0) return 0;

        // execute BFS 
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int iteration = 0;

        while(!q.empty()) {
            int size = q.size();
            bool has_rotten = 0;

            for(int i = 0; i < size; i++){
                auto& [ci, cj] = q.front();
                q.pop();

                for(auto& d : dirs) {
                    if (ci + d[0] < h && ci + d[0] >= 0 && 
                        cj + d[1] < w && cj + d[1] >= 0 &&
                        grid[ci + d[0]][cj + d[1]] == 1) {

                        grid[ci + d[0]][cj + d[1]] = 2;
                        q.push({ci + d[0], cj + d[1]});
                        fresh_count--;
                        has_rotten = 1;
                    }
                }
            }
            if (has_rotten) iteration++;
        }

        // for(int i = 0; i < h; i++) {
        //     for(int j = 0; j < w; j++) {
        //         if (grid[i][j] == 1) {
        //             return -1;
        //         }
        //     }
        // }

        if (fresh_count != 0) return -1;

        return iteration;
    }
};
