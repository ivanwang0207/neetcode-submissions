class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();

        // check how many fresh fruits in the 2d matrix
        int fresh = 0;
        std::queue<pair<int, int>> q;
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                if (grid[i][j] == 1) 
                    fresh++;
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        if (fresh == 0) return 0;    
        if (q.size() == 0) return -1;    

        const int directions[4][2] = 
            {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int mins = 0;
        while(!q.empty()) {
            int count = q.size();
            mins++;

            for(int n = 0; n < count; ++n) {
                auto [ci, cj] = q.front();
                q.pop();

                for(auto& d : directions) {
                    int ni = ci + d[0];
                    int nj = cj + d[1];
                    if(ni >= 0 && ni < height && nj >=0 && nj < width && 
                       grid[ni][nj] == 1){
                        q.push({ni, nj});
                        grid[ni][nj] = 2;
                        fresh--;
                    }
                }
            }
            if (fresh == 0) return mins;
        }

        if (fresh > 0) return -1;
        return mins;
    }
};
